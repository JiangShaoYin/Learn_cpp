 /// @date    2018-07-03 18:26:59
 
#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "Thread.h"
#include "TaskQueue.h"

class Producer : public wd::Thread {
	public:
		Producer(TaskQueue & tq) :_tq(tq) {}
	private:
		void run();
	private:
		TaskQueue & _tq;//定义引用变量_tq,初始化_tq(tq)时不发生复制，_tq指向tq所指的对象
};



#endif
