 /// @date    2018-07-02 19:41:03
 
#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace::wd;

struct Task {
	void task() {
		srand(time(NULL));
		int cnt=10;
		while(--cnt) {
			int num = rand()%100;
			cout << "SonThread " << pthread_self() 
				 << " get a num " << num << endl;
		}	
	}
};

void test1() { 
	cout << "Thread " << pthread_self() << endl;
	Thread task_thread(std::bind(&Task::task, Task()));//task函数向Thread注册
	task_thread.start();
	task_thread.join();
} 
 
int main(){
	test1();
	return 0;
}
