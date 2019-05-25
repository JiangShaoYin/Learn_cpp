 /// @date    2018-07-04 20:15:35
 
#include "ThreadPool.h"
#include "Producer.h"
#include <unistd.h>
#include <iostream>
#include <memory>
using namespace std;


int main() {
	cout << "mian thread id : " << pthread_self() << endl;
	Producer prod;
	ThreadPool tp(4,10);
	tp.start();
	int cnt = 30;
	while(cnt--) {
		tp.addTask(bind(&Producer::produce, prod));
		cout << "cnt = " << cnt <<endl;
	}
	tp.stop();
	return 0;	
}
