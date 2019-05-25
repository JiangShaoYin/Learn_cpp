 
 /// @file    construct_multi_derived.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 18:09:12
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base {
	public:
		Base() { cout << "Base()" << endl;}
		Base(int ib):_ib(ib) {cout << "Base(int)" << endl;}
	private:
		int _ib;

}; //end of Base

class Derived
:public Base
{
	public:
	//	Derived(int x)
	//		:_x(x){
	//			cout << "Derived(int x)" << endl; 
	//		}
	private:
		int _x;
};//end of Derived

int main(){
	Derived d;
	return 0;
}
