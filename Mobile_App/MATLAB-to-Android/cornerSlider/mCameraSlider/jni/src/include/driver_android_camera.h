/* driver_android_camera.h
 *
 * Copyright 2013-2014 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
void initCamera(double sampleTime, int location, int width, int height );
void getCameraData(uint8_t *outCh1, uint8_t *outCh2, uint8_t *outCh3);
void terminateCamera();
#ifdef __cplusplus
extern }
#endif