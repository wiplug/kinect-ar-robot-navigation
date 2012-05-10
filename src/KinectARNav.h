#ifndef KINECTARNAV_H_
#define KINECTARNAV_H_

#include "libfreenect/libfreenect.h"
#include "opencv2/opencv.hpp"
#include <pthread.h>

using namespace cv;

freenect_context *f_ctx;
freenect_device *f_dev;

class KinectARNav 
{
	Point3f pose_est;
	float conf;
	Mat kinect_rgb_frame;
	Mat kinect_depth_frame;

public:
	KinectARNav(const char*);
	Point3f getPoseEst();
	float getEstConf();
};

#endif /* KINECTARNAV_H_ */
