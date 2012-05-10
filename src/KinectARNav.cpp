#include "KinectARNav.h"

using namespace std;
using namespace cv;
using namespace json_spirit;

KinectARNav::KinectARNav(const char* conf_filename, PlayerCc::Position2dProxy* pp_arg, const char* map_img_filename, int pop_size) 
{
	this->pop_size = pop_size;

	// TODO: read known global marker coordinates from specified JSON file
	Value conf_json;
	
	use_map_img = false;

	if(map_img_filename != NULL)
	{
		use_map_img = true;
		// TODO: read map image
	}

	conf = 0.0;
	pose_est = Point3f(0.0f, 0.0f, 0.0f);
	kinect_rgb_frame = Mat(480, 640, CV_8UC3);
	kinect_depth_frame = Mat(480, 640, CV_8UC1);

	// TODO: initialize pose hypotheses
	pose_ests = new Point3f[pop_size];

	for(int k=0; k < pop_size; k++) {
		if(use_map_img)
		{
			// TODO: initialize only within valid map poses
		}
		else
		{
			// TODO: given no additional information, initialize anywhere within map area
			//pose_ests = Point3f();
		}
	}
}

void KinectARNav::run()
{
	// TODO: start threads to connect to Kinect, begin real-time particle filter localization, and 
	// perform potential field-based waypoint navigation as requested

	int rc = pthread_create(&kinect_reader_thread, NULL, runKinectReader, NULL);
      	
	if (rc != 0) {
		printf("ERROR; return code from pthread_create() is %d\n when starting Kinect reader thread", rc);
		exit(-1);
	}

	rc = pthread_create(&localization_thread, NULL, runLocalizer, NULL);

	if (rc != 0) {
                printf("ERROR; return code from pthread_create() is %d\n when starting localization thread", rc);
                exit(-1);
        }
	
	rc = pthread_create(&navigation_thread, NULL, runNavigator, NULL);

	if (rc != 0) {
                printf("ERROR; return code from pthread_create() is %d\n when starting navigation thread", rc);
                exit(-1);
        }
}

void KinectARNav::shutdown()
{
	// TODO: cleanly kill child threads and disconnect from devices
}

Point3f KinectARNav::getPoseEst()
{
	return pose_est;
}

double KinectARNav::getEstConf()
{
	return conf;
}

void KinectARNav::setMinResetConf(double min_conf)
{
	min_reset_conf = min_conf;
}

void KinectARNav::setMinLocalizedConf(double min_conf)
{
	min_localized_conf = min_conf;
}

void KinectARNav::setGoal(Point3f goal)
{
	this->goal = goal;
}

void KinectARNav::setGoalDistThreshold(double goal_threshold)
{
	this->goal_threshold = goal_threshold;
}

bool KinectARNav::atGoal()
{
	return false;
}

double KinectARNav::getSpeed()
{
	return 0.0;
}

double KinectARNav::getAngularSpeed()
{
	return 0.0;
}

