 
 /// @file    construct_multi_derived.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 18:09:12
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base {
	public:
		Base(){cout << "Base()" <<endl;}
		~Base(){cout << "~Base()" <<endl;}
};
class B {
	public:
		B(){cout << "B()" <<endl;}
		~B(){cout << "~B()" <<endl;}
};

class C
{
	public:
		C()	{cout << "C()" << endl;	}
		~C() { cout << "~C()" << endl;}
		void print() {cout << "print()" << endl;}
	private:
		int _ic;	
};

class Derived 
:public Base {
	public:
		Derived()
		:Base()
		,_c() {
			cout << "Derived::Base()" << endl;
		}
		void func() {_c.print();}
	private:
		C _c;
};

int main() {
	Derived d;
//	d.func();
	return 0;
}
