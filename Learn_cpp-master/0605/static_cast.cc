 ///
 /// @file    static_cast.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 21:35:44
 
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

void test(){
	int a=10;
	float b=static_cast <float> (a);
	cout<<""<<b<<endl;
	int *p=static_cast<int *> (malloc(sizeof(int)));
	*p=20;
	cout<<""<<*p<<endl;
	free(p);	
}
int main(){
	test();
}
