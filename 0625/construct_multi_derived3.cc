 
 /// @file    construct_multi_derived.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 18:09:12
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class A {
	public:
		A(){cout << "A()" <<endl;}
		~A(){cout << "~A()" <<endl;}
};
class B {
	public:
		B(){cout << "B()" <<endl;}
		~B(){cout << "~B()" <<endl;}
};

class C : public B, public A {
	public:
		C()
		:A()
		,B() { 
			cout << "C()" << endl;
			}
	~C() { cout << "~C()" << endl;}
};

int main() {
	C c;
	return 0;
}
