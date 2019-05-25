 /// @date    2018-07-04 20:15:35
 
#include "ThreadPool.h"
#include "WorkThread.h"
#include <unistd.h>
#include <iostream>
#include <memory>
using namespace std;


int main() {
	cout << "mian thread id : " << pthread_self() << endl;
	ThreadPool tp(4,10);
	unique_ptr<Task> task(new MyTask());
	tp.start();
	int cnt = 30;
	while(cnt--) {
		tp.addTask(task.get());
		cout << "cnt = " << cnt <<endl;
	}
	tp.stop();
	return 0;	
}
