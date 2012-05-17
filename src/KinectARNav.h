#ifndef KINECTARNAV_H_
#define KINECTARNAV_H_

#include <iostream>
#include <pthread.h>
#include <libplayerc++/playerc++.h>
#include <json_spirit.h>
#include "opencv2/opencv.hpp"
#include "KinectReader.h"
#include "Localizer.h"
#include "Navigator.h"
#include "Visualizer.h"

class KinectARNav 
{
private:
	PlayerCc::Position2dProxy* pp;
	bool visualizing;
	bool ready;
	Value config_file_json;
	KinectReader kinect_reader;
	Localizer localizer;
	Navigator navigator;
	Visualizer visualizer;

public:
	// default constructor
	KinectARNav();

	// TODO: full initializing constructor for use of library w/o configuration file

	// initialize library instance from specified configuration file
	int init(const char* config_filename_arg, PlayerCc::Position2dProxy* pp_arg, bool visualization_arg);

	// start threads to read from Kinect, estimate position with particle filter, display visualization if
	// specified, and compute navigation information
	void run();

	// returns true if child threads have been successfully started, and library instance is ready to
	// be polled for localization and navigation information
	bool ready();

	// disconnect from device and halt child threads
	void shutdown();
	
	// get current robot pose estimate, in form (x, y, theta)
	// Major-version TODO: include option for z-estimate (for variable terrain with sloped surfaces etc.)
	vector<double> getPoseEst();

	// return id-ordered list of waypoint names
	vector<string> getWaypoints();

	// set new goal waypoint for navigation system according to string waypoint name value; returns 
	// true if specified waypoint exists and is reachable, false otherwise
	bool setGoalWaypointByName(string);

	// set new goal waypoint for navigation system according to int waypoint id value; returns true
	// if specified waypoint exists and is reachable, false otherwise
	bool setGoalWaypointById(int);

	// returns true if pose estimate confidence is above threshold (as specified at initialization)
	bool localized()

	// returns true if localized position is within threshold distance of goal (as specified at initialization)
	bool atGoal();

	// get speed to set in order to navigate towards next waypoint on path to goal, as calculated by potential 
	// fields navigation/obstacle avoidance algorithm
	double getNavSpeed();
	
	// get angular speed to set (see above)
	double getNavTurnRate(); 

	// TODO: post-initialization accessors and modifiers for ARTK+/potential field/particle filter parameters
};

#endif /* KINECTARNAV_H_ */
