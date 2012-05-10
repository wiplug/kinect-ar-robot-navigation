#include "KinectARNav.h"

using namespace std;
using namespace cv;

KinectARNav::KinectARNav(const char* conf_filename) 
{
	// TODO: initialize from specified JSON file
	conf = 0.0;
	pose_est = Point3f(0.0f, 0.0f, 0.0f);
	kinect_rgb_frame = Mat(480, 640, CV_8UC3);
	kinect_depth_frame = Mat(480, 640, CV_8UC1);
}

Point3f KinectARNav::getPoseEst()
{
	return pose_est;
}

float KinectARNav::getEstConf()
{
	return conf;
}
