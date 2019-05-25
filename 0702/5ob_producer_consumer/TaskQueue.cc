 /// @date    2018-07-03 17:51:12
 
#include "TaskQueue.h"

bool TaskQueue::full() {  return _qsize== _que.size();}
bool TaskQueue::empty() {	return _que.size() == 0;}
void TaskQueue::push(Task task) {
	MutexLockGuard autolock(_mutex);
	while(full()) {					//队满，等待_notFull条件发生
		_notFull.wait();
	}
	_que.push(task);
	_notEmpty.notify();//通知等待_notEmpty条件的线程
}

Task TaskQueue::pop() {
	MutexLockGuard autolock(_mutex);
	while(empty()) {
		_notEmpty.wait();
	}
	Task tmp = _que.front();
	_que.pop();
	_notFull.notify();
	return tmp;
}

