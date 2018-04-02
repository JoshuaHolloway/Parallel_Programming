/* driver_android_display.h
 *
 * Copyright 2013 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
void initDisplay(int width, int height);
void putDisplayData(uint8_t *inY, uint8_t *inCb ,uint8_t *inCr);
void terminateDisplay();
#ifdef __cplusplus
extern }
#endif