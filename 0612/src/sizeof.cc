 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 10:18:55
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 1;
	printf("sizeof(a) = %ld\n", sizeof a);//sizeof并不是函数
	printf("sizeof(a) = %ld\n", sizeof(int));

	return 0;
}
