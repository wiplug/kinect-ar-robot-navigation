#ifndef KINECTREADER_H_
#define KINECTREADER_H_

#include "libfreenect/libfreenect.h"

freenect_context *f_ctx;
freenect_device *f_dev;

int freenect_angle = 0;
int freenect_led;

freenect_video_format requested_format = FREENECT_VIDEO_RGB;
freenect_video_format current_format = FREENECT_VIDEO_RGB;

int got_rgb = 0;
int got_depth = 0;

#endif /* KINECTREADER_H_ */
