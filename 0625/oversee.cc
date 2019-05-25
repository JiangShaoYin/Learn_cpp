 
 /// @file    oversee.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 21:11:03
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
  
class Base {
	public:
		Base() { cout << "Base()" << endl;}
		Base(int ib):_ib(ib) {cout << "Base(int)" << endl;}
		void func(int x) { cout << "Base::func()" << " " << x << endl;}
	private:
		int _ib;
}; //end of Base

class Derived
:public Base
{
	public:
		void func() { cout << "Derived::func()" << endl;}
	private:
		int _x;
};//end of Derived
 
int main(){
	Derived d;
//	d.func();
	d.Base::func(123321);
	return 0;
}
