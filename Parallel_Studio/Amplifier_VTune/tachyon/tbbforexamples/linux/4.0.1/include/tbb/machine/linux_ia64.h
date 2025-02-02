
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#if !defined(__TBB_machine_H) || defined(__TBB_machine_linux_ia64_H)
#error Do not #include this internal file directly; use public TBB headers instead.
#endif

#define __TBB_machine_linux_ia64_H

#include <stdint.h>
#include <unistd.h>
#include <ia64intrin.h>

#define __TBB_WORDSIZE 8
#define __TBB_BIG_ENDIAN 0

#if __INTEL_COMPILER
    #define __TBB_compiler_fence()
    #define __TBB_control_consistency_helper() __TBB_compiler_fence()
    #define __TBB_acquire_consistency_helper()
    #define __TBB_release_consistency_helper()
    #define __TBB_full_memory_fence()          __mf()
#else
    #define __TBB_compiler_fence() __asm__ __volatile__("": : :"memory")
    #define __TBB_control_consistency_helper() __TBB_compiler_fence()
    // Even though GCC imbues volatile loads with acquire semantics, it sometimes moves 
    // loads over the acquire fence. The following helpers stop such incorrect code motion.
    #define __TBB_acquire_consistency_helper() __TBB_compiler_fence()
    #define __TBB_release_consistency_helper() __TBB_compiler_fence()
    #define __TBB_full_memory_fence()          __asm__ __volatile__("mf": : :"memory")
#endif /* !__INTEL_COMPILER */

// Most of the functions will be in a .s file

extern "C" {
    int8_t __TBB_machine_fetchadd1__TBB_full_fence (volatile void *ptr, int8_t addend);
    int8_t __TBB_machine_fetchadd1acquire(volatile void *ptr, int8_t addend);
    int8_t __TBB_machine_fetchadd1release(volatile void *ptr, int8_t addend);

    int16_t __TBB_machine_fetchadd2__TBB_full_fence (volatile void *ptr, int16_t addend);
    int16_t __TBB_machine_fetchadd2acquire(volatile void *ptr, int16_t addend);
    int16_t __TBB_machine_fetchadd2release(volatile void *ptr, int16_t addend);

    int32_t __TBB_machine_fetchadd4__TBB_full_fence (volatile void *ptr, int32_t value);
    int32_t __TBB_machine_fetchadd4acquire(volatile void *ptr, int32_t addend);
    int32_t __TBB_machine_fetchadd4release(volatile void *ptr, int32_t addend);

    int64_t __TBB_machine_fetchadd8__TBB_full_fence (volatile void *ptr, int64_t value);
    int64_t __TBB_machine_fetchadd8acquire(volatile void *ptr, int64_t addend);
    int64_t __TBB_machine_fetchadd8release(volatile void *ptr, int64_t addend);

    int8_t __TBB_machine_fetchstore1__TBB_full_fence (volatile void *ptr, int8_t value);
    int8_t __TBB_machine_fetchstore1acquire(volatile void *ptr, int8_t value);
    int8_t __TBB_machine_fetchstore1release(volatile void *ptr, int8_t value);

    int16_t __TBB_machine_fetchstore2__TBB_full_fence (volatile void *ptr, int16_t value);
    int16_t __TBB_machine_fetchstore2acquire(volatile void *ptr, int16_t value);
    int16_t __TBB_machine_fetchstore2release(volatile void *ptr, int16_t value);

    int32_t __TBB_machine_fetchstore4__TBB_full_fence (volatile void *ptr, int32_t value);
    int32_t __TBB_machine_fetchstore4acquire(volatile void *ptr, int32_t value);
    int32_t __TBB_machine_fetchstore4release(volatile void *ptr, int32_t value);

    int64_t __TBB_machine_fetchstore8__TBB_full_fence (volatile void *ptr, int64_t value);
    int64_t __TBB_machine_fetchstore8acquire(volatile void *ptr, int64_t value);
    int64_t __TBB_machine_fetchstore8release(volatile void *ptr, int64_t value);

    int8_t __TBB_machine_cmpswp1__TBB_full_fence (volatile void *ptr, int8_t value, int8_t comparand); 
    int8_t __TBB_machine_cmpswp1acquire(volatile void *ptr, int8_t value, int8_t comparand); 
    int8_t __TBB_machine_cmpswp1release(volatile void *ptr, int8_t value, int8_t comparand); 

    int16_t __TBB_machine_cmpswp2__TBB_full_fence (volatile void *ptr, int16_t value, int16_t comparand);
    int16_t __TBB_machine_cmpswp2acquire(volatile void *ptr, int16_t value, int16_t comparand); 
    int16_t __TBB_machine_cmpswp2release(volatile void *ptr, int16_t value, int16_t comparand); 

    int32_t __TBB_machine_cmpswp4__TBB_full_fence (volatile void *ptr, int32_t value, int32_t comparand);
    int32_t __TBB_machine_cmpswp4acquire(volatile void *ptr, int32_t value, int32_t comparand); 
    int32_t __TBB_machine_cmpswp4release(volatile void *ptr, int32_t value, int32_t comparand); 

    int64_t __TBB_machine_cmpswp8__TBB_full_fence (volatile void *ptr, int64_t value, int64_t comparand);
    int64_t __TBB_machine_cmpswp8acquire(volatile void *ptr, int64_t value, int64_t comparand); 
    int64_t __TBB_machine_cmpswp8release(volatile void *ptr, int64_t value, int64_t comparand); 

    int64_t __TBB_machine_lg(uint64_t value);
    void __TBB_machine_pause(int32_t delay);
    bool __TBB_machine_trylockbyte( volatile unsigned char &ptr );
    int64_t __TBB_machine_lockbyte( volatile unsigned char &ptr );

    //! Retrieves the current RSE backing store pointer. IA64 specific.
    void* __TBB_get_bsp();

    int32_t __TBB_machine_load1_relaxed(const void *ptr);
    int32_t __TBB_machine_load2_relaxed(const void *ptr);
    int32_t __TBB_machine_load4_relaxed(const void *ptr);
    int64_t __TBB_machine_load8_relaxed(const void *ptr);

    void __TBB_machine_store1_relaxed(void *ptr, int32_t value);
    void __TBB_machine_store2_relaxed(void *ptr, int32_t value);
    void __TBB_machine_store4_relaxed(void *ptr, int32_t value);
    void __TBB_machine_store8_relaxed(void *ptr, int64_t value);
} // extern "C"

// Mapping old entry points to the names corresponding to the new full_fence identifier.
#define __TBB_machine_fetchadd1full_fence   __TBB_machine_fetchadd1__TBB_full_fence
#define __TBB_machine_fetchadd2full_fence   __TBB_machine_fetchadd2__TBB_full_fence
#define __TBB_machine_fetchadd4full_fence   __TBB_machine_fetchadd4__TBB_full_fence
#define __TBB_machine_fetchadd8full_fence   __TBB_machine_fetchadd8__TBB_full_fence
#define __TBB_machine_fetchstore1full_fence __TBB_machine_fetchstore1__TBB_full_fence
#define __TBB_machine_fetchstore2full_fence __TBB_machine_fetchstore2__TBB_full_fence
#define __TBB_machine_fetchstore4full_fence __TBB_machine_fetchstore4__TBB_full_fence
#define __TBB_machine_fetchstore8full_fence __TBB_machine_fetchstore8__TBB_full_fence
#define __TBB_machine_cmpswp1full_fence     __TBB_machine_cmpswp1__TBB_full_fence
#define __TBB_machine_cmpswp2full_fence     __TBB_machine_cmpswp2__TBB_full_fence 
#define __TBB_machine_cmpswp4full_fence     __TBB_machine_cmpswp4__TBB_full_fence
#define __TBB_machine_cmpswp8full_fence     __TBB_machine_cmpswp8__TBB_full_fence

// Mapping relaxed operations to the entry points implementing them.
/** On IA64 RMW operations implicitly have acquire semantics. Thus one cannot
    actually have completely relaxed RMW operation here. **/
#define __TBB_machine_fetchadd1relaxed      __TBB_machine_fetchadd1acquire
#define __TBB_machine_fetchadd2relaxed      __TBB_machine_fetchadd2acquire
#define __TBB_machine_fetchadd4relaxed      __TBB_machine_fetchadd4acquire
#define __TBB_machine_fetchadd8relaxed      __TBB_machine_fetchadd8acquire
#define __TBB_machine_fetchstore1relaxed    __TBB_machine_fetchstore1acquire
#define __TBB_machine_fetchstore2relaxed    __TBB_machine_fetchstore2acquire
#define __TBB_machine_fetchstore4relaxed    __TBB_machine_fetchstore4acquire
#define __TBB_machine_fetchstore8relaxed    __TBB_machine_fetchstore8acquire
#define __TBB_machine_cmpswp1relaxed        __TBB_machine_cmpswp1acquire
#define __TBB_machine_cmpswp2relaxed        __TBB_machine_cmpswp2acquire 
#define __TBB_machine_cmpswp4relaxed        __TBB_machine_cmpswp4acquire
#define __TBB_machine_cmpswp8relaxed        __TBB_machine_cmpswp8acquire

#define __TBB_MACHINE_DEFINE_ATOMICS(S,V)                               \
    template <typename T>                                               \
    struct machine_load_store_relaxed<T,S> {                      \
        static inline T load ( const T& location ) {                    \
            return (T)__TBB_machine_load##S##_relaxed(&location);       \
        }                                                               \
        static inline void store ( T& location, T value ) {             \
            __TBB_machine_store##S##_relaxed(&location, (V)value);      \
        }                                                               \
    }

namespace tbb {
namespace internal {
    __TBB_MACHINE_DEFINE_ATOMICS(1,int8_t);
    __TBB_MACHINE_DEFINE_ATOMICS(2,int16_t);
    __TBB_MACHINE_DEFINE_ATOMICS(4,int32_t);
    __TBB_MACHINE_DEFINE_ATOMICS(8,int64_t);
}} // namespaces internal, tbb

#undef __TBB_MACHINE_DEFINE_ATOMICS

#define __TBB_USE_FENCED_ATOMICS 1
#define __TBB_USE_GENERIC_HALF_FENCED_LOAD_STORE 1

// Definition of Lock functions
#define __TBB_TryLockByte(P) __TBB_machine_trylockbyte(P)
#define __TBB_LockByte(P)    __TBB_machine_lockbyte(P)

// Definition of other utility functions
#define __TBB_Pause(V) __TBB_machine_pause(V)
#define __TBB_Log2(V)  __TBB_machine_lg(V)
