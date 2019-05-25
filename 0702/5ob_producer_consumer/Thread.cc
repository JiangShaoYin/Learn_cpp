 /// @date    2018-07-02 13:39:41
#include "Thread.h" 
#include <iostream>
using std::endl;
using std::cout;
using namespace::wd;

wd::Thread::Thread(CallBack &&cb)	//传右值进来，交给cb，cb有名字，是左值
:_pid(0), _is_runing(false), _cb(std::move(cb)){}//_cb和cb都是function型，通过std::move,调用function(&&),开销小
void wd::Thread::start() {
	pthread_create(&_pid, NULL, ThreadFunc, this);
	cout << _pid << endl;
	_is_runing = true;
}

void wd::Thread::join() {
	pthread_join(_pid, NULL);
	_is_runing = false;
}

void* Thread::ThreadFunc(void* arg) {
	Thread* thread = static_cast<Thread*> (arg);//将void*型的this指针，强转为Thread*指针
	if(thread)
		thread->_cb();
	return NULL;
}
wd::Thread::~Thread() {
	if(_is_runing) {
		pthread_detach(_pid);
		_is_runing = false;
	}
}

