 /// @date    2018-07-03 19:58:00

#include "Producer.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

void Producer::run() {
	srand(time(NULL));
	int cnt = 8;
	while(cnt--) {
		int num = rand()%100;
		_tq.push(num);
		cout << cnt << " ";
		cout << "produce a num : " << num << endl;
		sleep(1);
	}
}
