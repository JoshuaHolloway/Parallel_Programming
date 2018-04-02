/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Sep-2015 15:39:50
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "myCorners.h"
#include "main.h"

/* Function Declarations */
static void argInit_352x288_uint8_T(unsigned char result[101376]);
static float argInit_real32_T(void);
static unsigned char argInit_uint8_T(void);
static void main_myCorners(void);

/* Function Definitions */

/*
 * Arguments    : unsigned char result[101376]
 * Return Type  : void
 */
static void argInit_352x288_uint8_T(unsigned char result[101376])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 352; idx0++) {
    for (idx1 = 0; idx1 < 288; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 352 * idx1] = argInit_uint8_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : unsigned char
 */
static unsigned char argInit_uint8_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_myCorners(void)
{
  static unsigned char R[101376];
  static unsigned char G[101376];
  unsigned char B[101376];

  /* Initialize function 'myCorners' input arguments. */
  /* Initialize function input argument 'R'. */
  argInit_352x288_uint8_T(R);

  /* Initialize function input argument 'G'. */
  argInit_352x288_uint8_T(G);

  /* Initialize function input argument 'B'. */
  argInit_352x288_uint8_T(B);

  /* Call the entry-point 'myCorners'. */
  myCorners(R, G, B, argInit_real32_T(), argInit_real32_T(), argInit_real32_T());
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  myCorners_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_myCorners();

  /* Terminate the application.
     You do not need to do this more than one time. */
  myCorners_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
