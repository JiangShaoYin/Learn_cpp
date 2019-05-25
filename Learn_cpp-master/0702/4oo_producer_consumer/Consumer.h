 /// @date    2018-07-03 20:05:11
 
#ifndef __CONSUMER_H__
#define __CONSUMER_H__
#include "TaskQueue.h"
#include "Thread.h"
#include <unistd.h>
#include <iostream>

class Consumer :public wd::Thread {
	public:
		Consumer(TaskQueue & tq) : _tq(tq) {}
		void run() {
			int cnt = 8;
			while(cnt--) {
				std::cout << "consume a num : " << _tq.pop() << std::endl;
				sleep(2);
			}
		}
	private:
		TaskQueue & _tq;
};
#endif
