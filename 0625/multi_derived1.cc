 
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
};
 
class B{
	public:
		void display() {	cout << "b" << endl;}
};
 
class C : public A, public B
{
};

int main(){
	C c;
	c.display();
	c.show();
	return 0;
}
