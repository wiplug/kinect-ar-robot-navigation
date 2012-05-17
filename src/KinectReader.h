#ifndef KINECTREADER_H_
#define KINECTREADER_H_

#include <pthread.h>
#include "libfreenect/libfreenect.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class KinectReader{
private:
	pthread_t reader_thread;

	freenect_context *f_ctx;
	freenect_device *f_dev;
	freenect_video_format requested_format;
        freenect_video_format current_format;

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
	void shutdown();
};

#endif /* KINECTREADER_H_ */
