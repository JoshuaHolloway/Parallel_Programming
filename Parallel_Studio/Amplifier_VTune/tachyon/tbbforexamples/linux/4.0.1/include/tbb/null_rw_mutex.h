
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#ifndef __TBB_null_rw_mutex_H
#define __TBB_null_rw_mutex_H

namespace tbb {
    
//! A rw mutex which does nothing
/** A null_rw_mutex is a rw mutex that does nothing and simulates successful operation.
    @ingroup synchronization */
class null_rw_mutex {
    //! Deny assignment and copy construction 
    null_rw_mutex( const null_rw_mutex& );   
    void operator=( const null_rw_mutex& );   
public:   
    //! Represents acquisition of a mutex.
    class scoped_lock {   
    public:   
        scoped_lock() {}
        scoped_lock( null_rw_mutex& , bool = true ) {}
        ~scoped_lock() {}
        void acquire( null_rw_mutex& , bool = true ) {}
        bool upgrade_to_writer() { return true; }
        bool downgrade_to_reader() { return true; }
        bool try_acquire( null_rw_mutex& , bool = true ) { return true; }
        void release() {}
    };
  
    null_rw_mutex() {}
    
    // Mutex traits   
    static const bool is_rw_mutex = true;   
    static const bool is_recursive_mutex = true;
    static const bool is_fair_mutex = true;
};  

}

#endif /* __TBB_null_rw_mutex_H */
