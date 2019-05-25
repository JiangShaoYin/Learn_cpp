 /// @date    2018-07-02 19:41:03
 
#include "Thread.h"
#include "TaskQueue.h"
#include "MutexLock.h"
#include "Condition.h"
#include <unistd.h>
#include <stdlib.h>
#include <memory>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace::wd;

struct Producer {
	void produce(TaskQueue & tq) {
		srand(time(NULL));
		int cnt=30;
		while(cnt--) {
			int num = rand()%100;
			tq.push(num);
			cout << " produce a num :" << num << endl;
			sleep(1);
		}	
	}
};

struct Consumer {
	void consumer(TaskQueue & tq) {
		int cnt = 30;
		while(cnt--){
		cout << "consumer a num :" << tq.pop() << endl;;
		sleep(2);
		}
	}
};


void test1() { 
	TaskQueue tq(10);
	cout << "Thread " << pthread_self() << endl;
	Thread producer(std::bind(&Producer::produce, Producer(), std::ref(tq)));
	Thread consumer(std::bind(&Consumer::consumer, Consumer(), std::ref(tq)));//tq对象不能复制，所以传引用进入函数

	producer.start();
	consumer.start();
	producer.join();
	consumer.join();
} 
 
int main(){
	test1();
	return 0;
}
