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

class SonThread:  public Thread {
virtual	void run();
}; 
void SonThread::run() {
	srand(time(NULL));
	int cnt=10;
	while(--cnt) {
		int num = rand()%100;
		cout << "SonThread " << pthread_self() 
			 << " get a num " << num << endl;
	}
}
 
void test1() { 
	cout << "Thread " << pthread_self() << endl;
	unique_ptr<Thread> son(new SonThread());
	son->start();
	son->join();
} 
 
int main(){
	test1();
	return 0;
}
