#include "Visualizer.h"

Visualizer::Visualizer()
{}

void* Visualizer::thread_main(void* arg)
{
	pthread_exit(NULL);
}

void Visualizer::run()
{}

void Visualizer::shutdown()
{}
