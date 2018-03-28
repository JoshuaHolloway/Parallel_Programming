
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#ifndef __TBB__flow_graph_types_impl_H
#define __TBB__flow_graph_types_impl_H

#ifndef __TBB_flow_graph_H
#error Do not #include this internal file directly; use public TBB headers instead.
#endif

namespace internal {
// wrap each element of a tuple in a template, and make a tuple of the result.

    template<int N, template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements;

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<1, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<2, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>, 
                PT<typename std::tuple_element<1,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<3, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<4, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<5, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type>,
                PT<typename std::tuple_element<4,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<6, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type>,
                PT<typename std::tuple_element<4,TypeTuple>::type>,
                PT<typename std::tuple_element<5,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<7, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type>,
                PT<typename std::tuple_element<4,TypeTuple>::type>,
                PT<typename std::tuple_element<5,TypeTuple>::type>,
                PT<typename std::tuple_element<6,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<8, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type>,
                PT<typename std::tuple_element<4,TypeTuple>::type>,
                PT<typename std::tuple_element<5,TypeTuple>::type>,
                PT<typename std::tuple_element<6,TypeTuple>::type>,
                PT<typename std::tuple_element<7,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<9, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type>,
                PT<typename std::tuple_element<4,TypeTuple>::type>,
                PT<typename std::tuple_element<5,TypeTuple>::type>,
                PT<typename std::tuple_element<6,TypeTuple>::type>,
                PT<typename std::tuple_element<7,TypeTuple>::type>,
                PT<typename std::tuple_element<8,TypeTuple>::type> >
            type;
    };

    template<template<class> class PT, typename TypeTuple>
    struct wrap_tuple_elements<10, PT, TypeTuple> {
        typedef typename std::tuple<
                PT<typename std::tuple_element<0,TypeTuple>::type>,
                PT<typename std::tuple_element<1,TypeTuple>::type>,
                PT<typename std::tuple_element<2,TypeTuple>::type>,
                PT<typename std::tuple_element<3,TypeTuple>::type>,
                PT<typename std::tuple_element<4,TypeTuple>::type>,
                PT<typename std::tuple_element<5,TypeTuple>::type>,
                PT<typename std::tuple_element<6,TypeTuple>::type>,
                PT<typename std::tuple_element<7,TypeTuple>::type>,
                PT<typename std::tuple_element<8,TypeTuple>::type>,
                PT<typename std::tuple_element<9,TypeTuple>::type> >
            type;
    };

}  // namespace internal
#endif  /* __TBB__flow_graph_types_impl_H */
