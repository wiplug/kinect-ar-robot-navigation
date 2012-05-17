#ifndef NAVIGATOR_H_
#define NAVIGATOR_H_

#include <pthread.h>
#include <cmath>

class Navigator
{
private:
	pthread_t navigator_thread;
	void* thread_main(void*);

public:
	Navigator();
	void run();
	void shutdown();
	bool atGoal();
	double getSpeed();
	double getTurnRate();
};

#endif /* NAVIGATOR_H_ */
