
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#ifndef __TBB_spin_rw_mutex_H
#define __TBB_spin_rw_mutex_H

#include "tbb_stddef.h"
#include "tbb_machine.h"
#include "tbb_profiling.h"

namespace tbb {

class spin_rw_mutex_v3;
typedef spin_rw_mutex_v3 spin_rw_mutex;

//! Fast, unfair, spinning reader-writer lock with backoff and writer-preference
/** @ingroup synchronization */
class spin_rw_mutex_v3 {
    //! @cond INTERNAL

    //! Internal acquire write lock.
    bool __TBB_EXPORTED_METHOD internal_acquire_writer();

    //! Out of line code for releasing a write lock.  
    /** This code is has debug checking and instrumentation for Intel(R) Thread Checker and Intel(R) Thread Profiler. */
    void __TBB_EXPORTED_METHOD internal_release_writer();

    //! Internal acquire read lock.
    void __TBB_EXPORTED_METHOD internal_acquire_reader();

    //! Internal upgrade reader to become a writer.
    bool __TBB_EXPORTED_METHOD internal_upgrade();

    //! Out of line code for downgrading a writer to a reader.   
    /** This code is has debug checking and instrumentation for Intel(R) Thread Checker and Intel(R) Thread Profiler. */
    void __TBB_EXPORTED_METHOD internal_downgrade();

    //! Internal release read lock.
    void __TBB_EXPORTED_METHOD internal_release_reader();

    //! Internal try_acquire write lock.
    bool __TBB_EXPORTED_METHOD internal_try_acquire_writer();

    //! Internal try_acquire read lock.
    bool __TBB_EXPORTED_METHOD internal_try_acquire_reader();

    //! @endcond
public:
    //! Construct unacquired mutex.
    spin_rw_mutex_v3() : state(0) {
#if TBB_USE_THREADING_TOOLS
        internal_construct();
#endif
    }

#if TBB_USE_ASSERT
    //! Destructor asserts if the mutex is acquired, i.e. state is zero.
    ~spin_rw_mutex_v3() {
        __TBB_ASSERT( !state, "destruction of an acquired mutex");
    };
#endif /* TBB_USE_ASSERT */

    //! The scoped locking pattern
    /** It helps to avoid the common problem of forgetting to release lock.
        It also nicely provides the "node" for queuing locks. */
    class scoped_lock : internal::no_copy {
    public:
        //! Construct lock that has not acquired a mutex.
        /** Equivalent to zero-initialization of *this. */
        scoped_lock() : mutex(NULL), is_writer(false) {}

        //! Acquire lock on given mutex.
        scoped_lock( spin_rw_mutex& m, bool write = true ) : mutex(NULL) {
            acquire(m, write);
        }

        //! Release lock (if lock is held).
        ~scoped_lock() {
            if( mutex ) release();
        }

        //! Acquire lock on given mutex.
        void acquire( spin_rw_mutex& m, bool write = true ) {
            __TBB_ASSERT( !mutex, "holding mutex already" );
            is_writer = write; 
            mutex = &m;
            if( write ) mutex->internal_acquire_writer();
            else        mutex->internal_acquire_reader();
        }

        //! Upgrade reader to become a writer.
        /** Returns true if the upgrade happened without re-acquiring the lock and false if opposite */
        bool upgrade_to_writer() {
            __TBB_ASSERT( mutex, "lock is not acquired" );
            __TBB_ASSERT( !is_writer, "not a reader" );
            is_writer = true; 
            return mutex->internal_upgrade();
        }

        //! Release lock.
        void release() {
            __TBB_ASSERT( mutex, "lock is not acquired" );
            spin_rw_mutex *m = mutex; 
            mutex = NULL;
#if TBB_USE_THREADING_TOOLS||TBB_USE_ASSERT
            if( is_writer ) m->internal_release_writer();
            else            m->internal_release_reader();
#else
            if( is_writer ) __TBB_AtomicAND( &m->state, READERS ); 
            else            __TBB_FetchAndAddWrelease( &m->state, -(intptr_t)ONE_READER);
#endif /* TBB_USE_THREADING_TOOLS||TBB_USE_ASSERT */
        }

        //! Downgrade writer to become a reader.
        bool downgrade_to_reader() {
#if TBB_USE_THREADING_TOOLS||TBB_USE_ASSERT
            __TBB_ASSERT( mutex, "lock is not acquired" );
            __TBB_ASSERT( is_writer, "not a writer" );
            mutex->internal_downgrade();
#else
            __TBB_FetchAndAddW( &mutex->state, ((intptr_t)ONE_READER-WRITER));
#endif /* TBB_USE_THREADING_TOOLS||TBB_USE_ASSERT */
            is_writer = false;

            return true;
        }

        //! Try acquire lock on given mutex.
        bool try_acquire( spin_rw_mutex& m, bool write = true ) {
            __TBB_ASSERT( !mutex, "holding mutex already" );
            bool result;
            is_writer = write; 
            result = write? m.internal_try_acquire_writer()
                          : m.internal_try_acquire_reader();
            if( result ) 
                mutex = &m;
            return result;
        }

    protected:
        //! The pointer to the current mutex that is held, or NULL if no mutex is held.
        spin_rw_mutex* mutex;

        //! If mutex!=NULL, then is_writer is true if holding a writer lock, false if holding a reader lock.
        /** Not defined if not holding a lock. */
        bool is_writer;
    };

    // Mutex traits
    static const bool is_rw_mutex = true;
    static const bool is_recursive_mutex = false;
    static const bool is_fair_mutex = false;

    // ISO C++0x compatibility methods

    //! Acquire writer lock
    void lock() {internal_acquire_writer();}

    //! Try acquiring writer lock (non-blocking)
    /** Return true if lock acquired; false otherwise. */
    bool try_lock() {return internal_try_acquire_writer();}

    //! Release lock
    void unlock() {
#if TBB_USE_THREADING_TOOLS||TBB_USE_ASSERT
        if( state&WRITER ) internal_release_writer();
        else               internal_release_reader();
#else
        if( state&WRITER ) __TBB_AtomicAND( &state, READERS ); 
        else               __TBB_FetchAndAddWrelease( &state, -(intptr_t)ONE_READER);
#endif /* TBB_USE_THREADING_TOOLS||TBB_USE_ASSERT */
    }

    // Methods for reader locks that resemble ISO C++0x compatibility methods.

    //! Acquire reader lock
    void lock_read() {internal_acquire_reader();}

    //! Try acquiring reader lock (non-blocking)
    /** Return true if reader lock acquired; false otherwise. */
    bool try_lock_read() {return internal_try_acquire_reader();}

private:
    typedef intptr_t state_t;
    static const state_t WRITER = 1;
    static const state_t WRITER_PENDING = 2;
    static const state_t READERS = ~(WRITER | WRITER_PENDING);
    static const state_t ONE_READER = 4;
    static const state_t BUSY = WRITER | READERS;
    //! State of lock
    /** Bit 0 = writer is holding lock
        Bit 1 = request by a writer to acquire lock (hint to readers to wait)
        Bit 2..N = number of readers holding lock */
    state_t state;

    void __TBB_EXPORTED_METHOD internal_construct();
};

__TBB_DEFINE_PROFILING_SET_NAME(spin_rw_mutex)

} // namespace tbb

#endif /* __TBB_spin_rw_mutex_H */
