 ///
 /// @file    static_cast.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 21:35:44
 
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

void test(){
	int a = 10;
	float b = static_cast<float> (a); // 静态转换”的意思，也就是在编译期间转换，转换失败的话会抛出一个编译错误
	cout << "" << b << endl;
	int *p = static_cast<int *> (malloc(sizeof(int)));
	*p = 20;
	cout<< ""<< *p << endl;
	free(p);	
}
int main(){
	test();
}
