 /// @date    2018-07-03 17:44:34

#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__
#include "Condition.h"
#include "MutexLock.h"
#include <queue>
using std::queue;

using Task = int;
class TaskQueue {
	public:
		TaskQueue(size_t qsize) : _qsize(qsize),
								 _notFull(_mutex),
								 _notEmpty(_mutex) {}
		bool empty();
		bool full();
		void push(Task);
		Task pop();
	private:
		size_t _qsize;
		queue<Task> _que;
		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
};


#endif
