#include "Localizer.h"

Localizer::Localizer() 
{}

// initialize particle filter	
void Localizer::initialize()
{
	// height and width are fixed for Kinect
	ar_cam_width = 640;
	ar_cam_height = 480;
}

void Localizer::run()
{}

void Localizer::shutdown()
{}

void* Localizer::thread_main(void* arg)
{
	pthread_exit(NULL);
}

void Localizer::propagate(double distance, double angle)
{}

void Localizer::assignWeights()
{}

void Localizer::resamplePoint(int i)
{}

double Localizer::getMeanX()
{
	return x_mean;
}

double Localizer::getMeanY()
{
	return y_mean;
}

double Localizer::getMeanTheta()
{
	return theta_mean;
}

double Localizer::getXVariance()
{
	return x_variance;
}

double Localizer::getYVariance()
{
	return y_variance;
}

double Localizer::getThetaVariance()
{
	return theta_variance;
}
