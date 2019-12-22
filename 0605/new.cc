 //
 /// @file    new.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 21:44:22
 
 
#include <iostream>
using std::cout;
using std::endl;

void func(){
	int *a = new int(10);
	int *b = new int [10]();
	cout << "" << *a << endl;
	cout << "" << *b << endl;
}
int  main(){
	func();
	return 0;
}
