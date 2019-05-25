 /// @date    2018-07-03 20:14:09

#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;

int main() {
	cout << "pid: " << pthread_self() << endl;
	TaskQueue tq(30);
	unique_ptr<wd::Thread> producer(new Producer(tq));
	unique_ptr<wd::Thread> consumer(new Consumer(tq));
	producer->start();
	consumer->start();

	producer->join();
	consumer->join();

	return 0;
}
