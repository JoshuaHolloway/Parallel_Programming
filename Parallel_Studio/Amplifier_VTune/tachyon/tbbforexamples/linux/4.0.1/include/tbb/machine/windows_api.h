
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
#ifndef __TBB_machine_windows_api_H
#define __TBB_machine_windows_api_H

#if _WIN32 || _WIN64

#if _XBOX

#define NONET
#define NOD3D
#include <xtl.h>

#else // Assume "usual" Windows

#include <windows.h>

#endif // _XBOX

#if !defined(_WIN32_WINNT)
// The following Windows API function is declared explicitly;
// otherwise any user would have to specify /D_WIN32_WINNT=0x0400
extern "C" BOOL WINAPI TryEnterCriticalSection( LPCRITICAL_SECTION );
#endif

#else
#error tbb/machine/windows_api.h should only be used for Windows based platforms
#endif // _WIN32 || _WIN64

#endif // __TBB_machine_windows_api_H
