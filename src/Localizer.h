#ifndef LOCALIZER_H_
#define LOCALIZER_H_

#include <pthread.h>
#include <cmath>
#include <string>
#include <ARToolKitPlus/TrackerSingleMarker.h>
#include "opencv2/opencv.hpp"
#include "KinectReader.h"

using namespace ARToolKitPlus;
using namespace cv;
using namespace std;

typedef struct {
	double xpos;
	double ypos;
	double theta;
	double weight;	
} hypothesis;

class Localizer {
private:
	pthread_t localizer_thread;

	// ARTK+ variables
	TrackerSingleMarker* tracker;
	int ar_cam_width; // Kinect RGB camera width
	int ar_cam_height; // Kinect RGB camera height
	string ar_calibration_filename;
	double ar_nearclip;
	double ar_farclip;
	PIXEL_FORMAT ar_pixel_format;
	double ar_patt_width;
	double ar_border_width;
	int ar_threshold;

	// particle filter variables
	int width;
	int height;
	int pop_size;
	int min_reset_iterations_interval;

	double x_mean;
	double y_mean;
	double theta_mean;

	double x_variance;
	double y_variance;
	double theta_variance;

	double resample_weight_threshold;
	double reset_avg_conf_threshold;
	double localized_conf_threshold;

	hypothesis* hypotheses;

	string map_image_fname;
	Mat map_image;

	void* thread_main(void* arg);

public:
	// TODO: flesh out constructor
	Localizer();

	// initialize particle filter	
	void initialize();

	void run();

	void shutdown();

	void propagate(double distance, double angle);
	
	void assignWeights();
	
	void resamplePoint(int i);
	
	double getMeanX();
	
	double getMeanY();
	
	double getMeanTheta();
	
	double getXVariance();
	
	double getYVariance();
	
	double getThetaVariance();
};

#endif /* LOCALIZER_H_ */
