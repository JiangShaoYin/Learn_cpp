/// @date    2018-07-04 14:39:31

#ifndef __TASK_H__
#define __TASK_H__
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Task {
	public:
		virtual void process() = 0;
};

class MyTask : public Task {
	public:
		void process() {
			srand(time(NULL));
			int number = rand() % 100;
			cout << ">>> subThread: "<< pthread_self() << ". produce a number : " << number << endl;
			sleep(1);
		}
};
#endif
