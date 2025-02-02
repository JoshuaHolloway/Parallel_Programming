
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#if !defined(__TBB_machine_H) || defined(__TBB_machine_linux_intel64_H)
#error Do not #include this internal file directly; use public TBB headers instead.
#endif

#define __TBB_machine_linux_intel64_H

#include <stdint.h>
#include <unistd.h>

#define __TBB_WORDSIZE 8
#define __TBB_BIG_ENDIAN 0

#define __TBB_compiler_fence() __asm__ __volatile__("": : :"memory")
#define __TBB_control_consistency_helper() __TBB_compiler_fence()
#define __TBB_acquire_consistency_helper() __TBB_compiler_fence()
#define __TBB_release_consistency_helper() __TBB_compiler_fence()

#ifndef __TBB_full_memory_fence
#define __TBB_full_memory_fence() __asm__ __volatile__("mfence": : :"memory")
#endif

#define __TBB_MACHINE_DEFINE_ATOMICS(S,T,X)                                          \
static inline T __TBB_machine_cmpswp##S (volatile void *ptr, T value, T comparand )  \
{                                                                                    \
    T result;                                                                        \
                                                                                     \
    __asm__ __volatile__("lock\ncmpxchg" X " %2,%1"                                  \
                          : "=a"(result), "=m"(*(volatile T*)ptr)                    \
                          : "q"(value), "0"(comparand), "m"(*(volatile T*)ptr)       \
                          : "memory");                                               \
    return result;                                                                   \
}                                                                                    \
                                                                                     \
static inline T __TBB_machine_fetchadd##S(volatile void *ptr, T addend)              \
{                                                                                    \
    T result;                                                                        \
    __asm__ __volatile__("lock\nxadd" X " %0,%1"                                     \
                          : "=r"(result),"=m"(*(volatile T*)ptr)                     \
                          : "0"(addend), "m"(*(volatile T*)ptr)                      \
                          : "memory");                                               \
    return result;                                                                   \
}                                                                                    \
                                                                                     \
static inline  T __TBB_machine_fetchstore##S(volatile void *ptr, T value)            \
{                                                                                    \
    T result;                                                                        \
    __asm__ __volatile__("lock\nxchg" X " %0,%1"                                     \
                          : "=r"(result),"=m"(*(volatile T*)ptr)                     \
                          : "0"(value), "m"(*(volatile T*)ptr)                       \
                          : "memory");                                               \
    return result;                                                                   \
}                                                                                    \
                                                                                     
__TBB_MACHINE_DEFINE_ATOMICS(1,int8_t,"")
__TBB_MACHINE_DEFINE_ATOMICS(2,int16_t,"")
__TBB_MACHINE_DEFINE_ATOMICS(4,int32_t,"")
__TBB_MACHINE_DEFINE_ATOMICS(8,int64_t,"q")

#undef __TBB_MACHINE_DEFINE_ATOMICS

static inline int64_t __TBB_machine_lg( uint64_t x ) {
    int64_t j;
    __asm__ ("bsr %1,%0" : "=r"(j) : "r"(x));
    return j;
}

static inline void __TBB_machine_or( volatile void *ptr, uint64_t addend ) {
    __asm__ __volatile__("lock\norq %1,%0" : "=m"(*(volatile uint64_t*)ptr) : "r"(addend), "m"(*(volatile uint64_t*)ptr) : "memory");
}

static inline void __TBB_machine_and( volatile void *ptr, uint64_t addend ) {
    __asm__ __volatile__("lock\nandq %1,%0" : "=m"(*(volatile uint64_t*)ptr) : "r"(addend), "m"(*(volatile uint64_t*)ptr) : "memory");
}

#define __TBB_AtomicOR(P,V) __TBB_machine_or(P,V)
#define __TBB_AtomicAND(P,V) __TBB_machine_and(P,V)

// Definition of other functions
#ifndef __TBB_Pause
static inline void __TBB_machine_pause( int32_t delay ) {
    for (int32_t i = 0; i < delay; i++) {
       __asm__ __volatile__("pause;");
    }
    return;
}
#define __TBB_Pause(V) __TBB_machine_pause(V)
#endif /* !__TBB_Pause */

#define __TBB_Log2(V)  __TBB_machine_lg(V)

#define __TBB_USE_FETCHSTORE_AS_FULL_FENCED_STORE   1
#define __TBB_USE_GENERIC_HALF_FENCED_LOAD_STORE    1
#define __TBB_USE_GENERIC_RELAXED_LOAD_STORE        1

// API to retrieve/update FPU control setting
#ifndef __TBB_CPU_CTL_ENV_PRESENT
#define __TBB_CPU_CTL_ENV_PRESENT 1

struct __TBB_cpu_ctl_env_t {
    int     mxcsr;
    short   x87cw;
};

inline void __TBB_get_cpu_ctl_env ( __TBB_cpu_ctl_env_t* ctl ) {
#if __TBB_ICC_12_0_INL_ASM_FSTCW_BROKEN
    __TBB_cpu_ctl_env_t loc_ctl;
    __asm__ __volatile__ (
            "stmxcsr %0\n\t"
            "fstcw %1"
            : "=m"(loc_ctl.mxcsr), "=m"(loc_ctl.x87cw)
    );
    *ctl = loc_ctl;
#else
    __asm__ __volatile__ (
            "stmxcsr %0\n\t"
            "fstcw %1"
            : "=m"(ctl->mxcsr), "=m"(ctl->x87cw)
    );
#endif
}
inline void __TBB_set_cpu_ctl_env ( const __TBB_cpu_ctl_env_t* ctl ) {
    __asm__ __volatile__ (
            "ldmxcsr %0\n\t"
            "fldcw %1"
            : : "m"(ctl->mxcsr), "m"(ctl->x87cw)
    );
}
#endif /* !__TBB_CPU_CTL_ENV_PRESENT */
