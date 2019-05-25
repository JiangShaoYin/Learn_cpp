 /// @date    2018-07-04 13:32:51

#ifndef __WORKTHREAD_H__
#define __WORKTHREAD_H__
#include "Thread.h"
#include "ThreadPool.h"

class WorkThread :public Thread {
	public:
		WorkThread(ThreadPool & tp)
			:_tp(tp) {}
		void run() {
			_tp.threadFunc();
		}
	~WorkThread() {cout << "~WorkThread" << endl;}
	private:
		ThreadPool& _tp; 
};
#endif
