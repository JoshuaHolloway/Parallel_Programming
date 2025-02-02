
/*****************************************************************************
Copyright 2017 Intel Corporation.

The source code, information and material ("Material") contained herein is owned by Intel Corporation or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed in any way without Intel's prior express written permission. No license under any patent, copyright or other intellectual property rights in the Material is granted to or conferred upon you, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.

Include any supplier copyright notices as supplier requires Intel to use.

Include supplier trademarks or logos as supplier requires Intel to use, preceded by an asterisk. An asterisked footnote can be added as follows: *Third Party trademarks are the property of their respective owners.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded in Materials by Intel or Intel's suppliers or licensors in any way."
*****************************************************************************/
/*
    The original source for this example is
    Copyright (c) 1994-2008 John E. Stone
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. The name of the author may not be used to endorse or promote products
       derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
*/

/*
 * util.c - Contains all of the timing functions for various platforms.
 *
 *  $Id: util.cpp,v 1.6 2007-02-22 18:17:51 Intel Exp $ 
 */

#include "machine.h"
#include "types.h"
#include "macros.h"
#include "util.h"
#include "light.h"
#include "global.h"
#include "ui.h"

void rt_finalize(void);

#ifndef _WIN32
#include <sys/time.h>
#include <unistd.h>

void rt_sleep(int msec) {
    usleep(msec*1000);
}

#else //_WIN32

#undef OLDUNIXTIME
#undef STDTIME

#include <windows.h>

void rt_sleep(int msec) {
    Sleep(msec);
}

DWORD starttime;
DWORD stoptime;

void timerstart(void) {
    starttime = GetTickCount ();
}

void timerstop(void) {
    stoptime = GetTickCount ();
}

flt timertime(void) {
   double ttime, start, end;

   start = ((double) starttime) / ((double) 1000.00);
     end = ((double) stoptime) / ((double) 1000.00);
   ttime = end - start;

   return ttime;
}
#endif  /*  _WIN32  */

/* if we're on a Unix with gettimeofday() we'll use newer timers */
#ifdef STDTIME 
  struct timeval starttime, endtime;
  struct timezone tz;
 
void timerstart(void) {
  gettimeofday(&starttime, &tz);
} 
  
void timerstop(void) {
  gettimeofday(&endtime, &tz);
} 
  
flt timertime(void) {
   double ttime, start, end;

   start = (starttime.tv_sec+1.0*starttime.tv_usec / 1000000.0);
     end = (endtime.tv_sec+1.0*endtime.tv_usec / 1000000.0);
   ttime = end - start;

   return ttime;
}  
#endif  /*  STDTIME  */



/* use the old fashioned Unix time functions */
#ifdef OLDUNIXTIME
time_t starttime;
time_t stoptime;

void timerstart(void) {
  starttime=time(NULL);
}

void timerstop(void) {
  stoptime=time(NULL);
}

flt timertime(void) {
  flt a;
  a = difftime(stoptime, starttime);
  return a;
}
#endif  /*  OLDUNIXTIME  */



/* random other helper utility functions */
int rt_meminuse(void) {
  return rt_mem_in_use;
}  

void * rt_getmem(unsigned int bytes) {
  void * mem;

  mem=malloc( bytes );
  if (mem!=NULL) { 
    rt_mem_in_use += bytes;
  } 
  else {
    rtbomb("No more memory!!!!");
  }
  return mem;
}

unsigned int rt_freemem(void * addr) {
  unsigned int bytes;

  free(addr);

  bytes=0;
  rt_mem_in_use -= bytes; 
  return bytes;
}

void rtbomb(const char * msg) {
    rt_ui_message(MSG_ERR, msg);
    rt_ui_message(MSG_ABORT, "Rendering Aborted.");

  rt_finalize();
  exit(1);
}

void rtmesg(const char * msg) {
    rt_ui_message(MSG_0, msg);
}
