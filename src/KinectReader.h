#ifndef KINECTREADER_H_
#define KINECTREADER_H_

#include <pthread>
#include "libfreenect/libfreenect.h"
#include "opencv2/opencv.hpp"

class KinectReader{
private:
	pthread_t reader_thread;

	freenect_context *f_ctx;
	freenect_device *f_dev;
	freenect_video_format requested_format = FREENECT_VIDEO_RGB;
        freenect_video_format current_format = FREENECT_VIDEO_RGB;

	int freenect_angle;
	int freenect_led;
	int got_rgb;
	int got_depth;

	void* thread_main(void*);

public:
	Mat kinect_rgb_frame;
	Mat kinect_depth_frame;
	
	KinectReader();
	void run();
	void* thread_main(void*);
	void shutdown();
}

#endif /* KINECTREADER_H_ */
