
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
 * light.c - This file contains declarations and defines for light sources.
 *
 *  $Id: light.cpp,v 1.2 2007-02-22 17:54:15 dpoulsen Exp $
 */

#include "machine.h"
#include "types.h"
#include "macros.h"
#include "vector.h"
#include "intersect.h"
#include "util.h"

#define LIGHT_PRIVATE
#include "light.h"

static object_methods light_methods = {
  (void (*)(void *, void *))(light_intersect),
  (void (*)(void *, void *, void *, void *))(light_normal),
  light_bbox, 
  free 
};

point_light * newlight(void * tex, vector ctr, flt rad) {
  point_light * l;
  
  l=(point_light *) rt_getmem(sizeof(point_light));
  memset(l, 0, sizeof(point_light));
  l->methods = &light_methods;

  l->tex=(texture *)tex;
  l->ctr=ctr;
  l->rad=rad;

  return l;
}

static int light_bbox(void * obj, vector * min, vector * max) {
  return 0; /* lights are unbounded currently */
}

static void light_intersect(point_light * l, ray * ry) {
  flt b, disc, t1, t2, temp;
  vector V;

  /* Lights do not cast shadows.. */
  if (ry->flags & RT_RAY_SHADOW)
    return;

  VSUB(l->ctr, ry->o, V);
  VDOT(b, V, ry->d); 
  VDOT(temp, V, V);  

  disc=b*b + l->rad*l->rad - temp;

  if (disc<=0.0) return;
  disc=sqrt(disc);

  t2=b+disc;
  if (t2 <= SPEPSILON) 
    return;
  add_intersection(t2, (object *) l, ry);  

  t1=b-disc;
  if (t1 > SPEPSILON) 
    add_intersection(t1, (object *) l, ry);  
}

static void light_normal(point_light * l, vector * pnt, ray * incident, vector * N) {
  VSub((vector *) pnt, &(l->ctr), N);

  VNorm(N);

  if (VDot(N, &(incident->d)) > 0.0)  {
    N->x=-N->x;
    N->y=-N->y;
    N->z=-N->z;
  } 
}


