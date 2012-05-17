#include "KinectARNav.h"

using namespace std;
using namespace cv;
using namespace json_spirit;

KinectARNav::KinectARNav() 
{
	ready = false;
}

void KinectARNav::init(const char* conf_filename, PlayerCc::Position2dProxy* pp_arg, bool visualization_arg)
{
	// TODO: parse JSON configuration file and initialize library objects
	kinect_reader();
	localizer();
	navigator();
	
	if(visualizing)
	{
		visualizer();
	}
}

void KinectARNav::run()
{
	// TODO: start threads to connect to Kinect, begin real-time particle filter localization, and 
	// perform potential field-based waypoint navigation as requested
	kinect_reader.run();
	localizer.run();
	navigator.run();
	
	if(visualizing)
	{
		visualizer.run();
	}

}

void KinectARNav::shutdown()
{
	// TODO: cleanly kill child threads and disconnect from devices
	visualizer.shutdown();
	navigator.shutdown();
	localizer.shutdown();
	kinect_reader.shutdown();
}

vector<double> KinectARNav::getPoseEst()
{
	vector<double> pose;

	pose.push_back(localizer.getMeanX());
	pose.push_back(localizer.getMeanY());
	pose.push_back(localizer.getMeanTheta());

	return pose;
}

bool KinectARNav::setGoalWaypointByName(string waypoint_name)
{
	//goal_waypoint = ;
	return false;
}

bool KinectARNav::setGoalWaypointById(int waypoint_id)
{
        //goal_waypoint = ;
        return false;
}

bool KinectARNav::localized()
{
	return false;
}

bool KinectARNav::atGoal()
{
	return navigator.atGoal();
}

double KinectARNav::getNavSpeed()
{
	return navigator.getSpeed();
}

double KinectARNav::getNavTurnRate()
{
	return navigator.getTurnRate();
}

// TODO: add getters and setters for particle filter/potential fields/ARTKP/etc parameters
