 
 /// @file    bind.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-19 20:29:52
 
#include <functional> 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Example{
	int add(int x,int y) {
		return x+y;
	}	
};

int add(int x,int y) {
	cout << "x=" << x
		 << " "  << "y="
		 << y << " "
		 << endl;
	return x+y;
} 

void func(int x, const int & y) {
	cout << "x=" << x
		 << " "  << "y="
		 << y << " "
		 << endl;
}

void test1() {
	auto f1 = std::bind(add,10,20);
	cout << f1() << endl;
	auto f2 = std::bind(add,10,std::placeholders::_1);
	cout << f2(30,40) << endl;
	Example e;
	auto f3 = std::bind(&Example::add, &e, 8123,20);
	cout << f3() << endl;
	auto f4 = std::bind(&Example::add,std::placeholders::_1, 333, std::placeholders::_3);
	cout << f4(&e,2,3) << endl;
}
  
void test2() {
	std::function<int()> f1 = std::bind(add,10,20);
	cout << f1() << endl;
	std::function<int(int)> f2 = std::bind(add,10,std::placeholders::_1);
	cout << f2(30) << endl;
	Example e;
	f1 = std::bind(&Example::add, &e, 8123,20);
	cout << f1() << endl;
	std::function<int(Example*,int)> f4 = std::bind(&Example::add,std::placeholders::_1, 333, std::placeholders::_2);
	cout << f4(&e,2) << endl;
	int x=10;
	std::function<void()> f5 = std::bind(func,x,std::cref(x));
	x=20;
	f5();
}
int main(){
	test2();
	return 0;
}
