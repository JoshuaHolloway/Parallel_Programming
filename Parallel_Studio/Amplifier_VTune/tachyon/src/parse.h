
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
 * parse.h - this file contains defines for model file reading.
 *
 *  $Id: parse.h,v 1.2 2007-02-22 17:54:16 dpoulsen Exp $
 */

#define PARSENOERR       0
#define PARSEBADFILE     1
#define PARSEBADSUBFILE  2
#define PARSEBADSYNTAX   4
#define PARSEEOF         8
#define PARSEALLOCERR    16
 
unsigned int readmodel(char *, SceneHandle);

#ifdef PARSE_INTERNAL
#define NUMTEXS 32768
#define TEXNAMELEN 24

typedef struct {
   double rx1; double rx2; double rx3;
   double ry1; double ry2; double ry3;
   double rz1; double rz2; double rz3;
} RotMat;

typedef struct {
        char name[TEXNAMELEN];
        void * tex;
} texentry;

#ifdef _ERRCODE_DEFINED
#define errcode errcode_t
#endif//_ERRCODE_DEFINED
typedef unsigned int errcode;

static errcode add_texture(void * tex, char name[TEXNAMELEN]);
static errcode GetString(FILE *, const char *);
static errcode GetScenedefs(FILE *, SceneHandle);
static errcode GetColor(FILE *, color *);
static errcode GetVector(FILE *, vector *);
static errcode GetTexDef(FILE *);
static errcode GetTexAlias(FILE *);
static errcode GetTexture(FILE *, void **);
void * GetTexBody(FILE *);
static errcode GetBackGnd(FILE *);
static errcode GetCylinder(FILE *);
static errcode GetFCylinder(FILE *);
static errcode GetPolyCylinder(FILE *);
static errcode GetSphere(FILE *);
static errcode GetPlane(FILE *);
static errcode GetRing(FILE *);
static errcode GetBox(FILE *);
static errcode GetVol(FILE *);
static errcode GetTri(FILE *);
static errcode GetSTri(FILE *);
static errcode GetLight(FILE *);
static errcode GetLandScape(FILE *);
static errcode GetTPolyFile(FILE *);
static errcode GetMGFFile(FILE *, SceneHandle);
static errcode GetObject(FILE *, SceneHandle);

#endif
