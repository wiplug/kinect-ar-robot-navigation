#include "Navigator.h"

Navigator::Navigator()
{

}

void* Navigator::thread_main(void* arg)
{
	pthread_exit(NULL);
}

void Navigator::run()
{

}

void Navigator::shutdown()
{

}

bool Navigator::atGoal()
{
	return false;
}

double Navigator::getSpeed()
{
	return 0;
}

double Navigator::getTurnRate()
{
	return 0;
}
