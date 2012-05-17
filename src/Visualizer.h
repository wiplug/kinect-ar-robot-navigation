#ifndef VISUALIZER_H_
#define VISUALIZER_H_

#include <pthread>
#include <opencv2/opencv.hpp>

class Visualizer
{
private:
	pthread_t visualizer_thread;
	void* thread_main(void*);

public:
	Visualizer();
	void run();
	void shutdown();
}

#endif /* VISUALIZER_H_ */
