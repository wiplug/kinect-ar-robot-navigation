#ifndef KINECTARNAV_H_
#define KINECTARNAV_H_

#include "ARToolKitPlus/TrackerSingleMarker.h"
#include "libfreenect/libfreenect.h"
#include "opencv2/opencv.hpp"
#include <libplayerc++/playerc++.h>
#include <pthread.h>

using ARToolKitPlus::TrackerSingleMarker;
using namespace cv;

class KinectARNav 
{
	PlayerCc::Position2dProxy* pp;
	TrackerSingleMarker* tracker;
	freenect_context *f_ctx;
	freenect_device *f_dev;

	Point3f* pose_ests;
	Point3f pose_est;
	Point3f goal;
	bool use_map_img;
	int pop_size;
	double conf;
	double min_reset_conf;
	double min_localized_conf;
	double goal_threshold;
	Mat kinect_rgb_frame;
	Mat kinect_depth_frame;

public:
	// create new library instance
	KinectARNav(const char* conf_filename, PlayerCc::Position2dProxy* pp_arg, const char* map_img_filename=NULL, int pop_size=2000);

	// start client threads, connect to Kinect, and begin real-time particle filter localization
	void run();

	// cleanly kill child threads and disconnect from devices
	void shutdown();
	
	// get current robot pose estimate, in form (x, y, theta)
	// TODO: include z estimate (for outdoors, sloped surfances, etc)?
	Point3f getPoseEst();
	
	// get confidence of localization estimate; ranges from 0.0 (no confidence) to 1.0 (full confidence)
	double getEstConf();

	// set minimum aggregate estimate confidence, below which we will completely reinitialize PF every N iterations
	// TODO: specify or paramterize N
	void setMinResetConf(double min_conf);

	// set minimum confidence value above which we consider the localization estimate to be sufficient for navigation
	void setMinLocalizedConf(double min_conf);

	// set new goal for potential fields navigation algorithm
	void setGoal(Point3f goal);

	// set goal x,y distance threshold
	void setGoalDistThreshold(double goal_threshold);

	// returns true if current pose estimate is within given threshold distance of goal, and conf > 0.85
	bool atGoal();

	// get speed to set as calculated by potential fields navigation algorithm
	double getSpeed();
	
	// get angular speed to set as calculated by potential fields navigation algorithm
	double getAngularSpeed(); 
};

#endif /* KINECTARNAV_H_ */
