
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#ifndef __TBB_parallel_for_each_H
#define __TBB_parallel_for_each_H

#include "parallel_do.h"

namespace tbb {

//! @cond INTERNAL
namespace internal {
    // The class calls user function in operator()
    template <typename Function, typename Iterator>
    class parallel_for_each_body : internal::no_assign {
        const Function &my_func;
    public:
        parallel_for_each_body(const Function &_func) : my_func(_func) {}
        parallel_for_each_body(const parallel_for_each_body<Function, Iterator> &_caller) : my_func(_caller.my_func) {}

        void operator() ( typename std::iterator_traits<Iterator>::reference value ) const {
            my_func(value);
        }
    };
} // namespace internal
//! @endcond

/** \name parallel_for_each
    **/
//@{
//! Calls function f for all items from [first, last) interval using user-supplied context
/** @ingroup algorithms */
#if __TBB_TASK_GROUP_CONTEXT
template<typename InputIterator, typename Function>
void parallel_for_each(InputIterator first, InputIterator last, const Function& f, task_group_context &context) {
    internal::parallel_for_each_body<Function, InputIterator> body(f);
    tbb::parallel_do (first, last, body, context);
}
#endif /* __TBB_TASK_GROUP_CONTEXT */

//! Uses default context
template<typename InputIterator, typename Function>
void parallel_for_each(InputIterator first, InputIterator last, const Function& f) {
    internal::parallel_for_each_body<Function, InputIterator> body(f);
    tbb::parallel_do (first, last, body);
}

//@}

} // namespace

#endif /* __TBB_parallel_for_each_H */
