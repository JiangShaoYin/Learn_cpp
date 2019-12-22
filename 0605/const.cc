 ///
 /// @file    const.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 18:31:21
 
 
#include <iostream>
using std::cout;
using std::endl;
	int a=100,b=1;

void test2(){
	int* const ptr = &a; // 顶层const，ptr指针不变
	// ptr = NULL; //  error: assignment of read-only variable 'ptr'
	*ptr = b;  // ptr指向的内容可以改变
	cout<< "*ptr = " << *ptr << endl;
}

int main(){
	const int* p = &a;
	p = &b;
	cout<< "*p = " << *p << endl;
	test2();
	return 0;
}
