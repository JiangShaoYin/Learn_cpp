 
 /// @file    multi_derived.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 17:12:16
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class A{
	public:
		void show() {	cout << "A" << endl;}
	private:
		int _ia;
};
 
class B
:public A
//:virtual public A
{
	private:
		int _ib;
};
 

class C 
//:virtual public A
: public A
{
	private:
		int _ic;
};

class D 
:public B
,public C
{
	private:
		int _id;
};

int main(){
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
	return 0;
}
