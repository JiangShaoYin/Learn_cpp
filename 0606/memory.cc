 
#include<stdio.h> 
#include <iostream>
using std::cout;
using std::endl;
const int e=10; 
static int i=30; 
int a=0;
char *p; 
 int test(){
	cout<<&a<<endl;
	cout<<&p<<endl;
	cout<<&e<<endl;
	cout<<&i<<endl;
	cout<<"-----------------------"<<endl;
	char*s1=new char[5];
	const char*s2="123";
	printf("%p\n",s1);
	printf("%p\n",s2);
	printf("%p\n",test);



 }



int main(){
	test();
	printf("%p\n",main);
	return 0;
}
