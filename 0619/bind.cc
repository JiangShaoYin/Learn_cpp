 
 /// @file    bind.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-19 20:29:52
 
#include <functional> 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Example{
	int add(int x,int y) {  // 结构体成员函数的第一个参数是this，隐式表达。但是在绑定函数时，要把结构体的地址this指针，做第1个参数，显式的传过去，可以在对象前加&传this指针
		return x+y;
	}	
};

int add(int x,int y) {
	cout << "x=" << x  << " "  << "y="	 << y << " " << endl;
	return x+y;
} 

void print(int x, const int & y) {
	cout << "x=" << x << " "  << "y=" << y << " "	 << endl;
}

void test1() {
	auto f1 = std::bind(add,10,20);
	f1();
	// cout << f1() << endl;
	cout << "f1()" << endl;

	auto f2 = std::bind(add,10,std::placeholders::_2); // 函数f2 绑定add函数，参数1固定为10， 参数2保持与f2中的第2个参数一致.

	cout << f2(30,40) << endl;

	Example e;
	auto f3 = std::bind(&Example::add, &e, 8123,20); // 绑定Example结构体的成员函数add，因为add在结构体中，所以add函数的第一个参数是this，用&e传入this指针
	cout << f3() << endl;

	auto f4 = std::bind(&Example::add,std::placeholders::_1, 333, std::placeholders::_4);// 函数f4 绑定Example结构体中的add成员函数，参数1由f4()的第1参数&e传入，
																						 // 参数2固定333，参数3由f4()的第4参数传入，.
	cout << f4(&e,2,3,4) << endl;  // 输出：337
}
  
void test2() {
	std::function<int()> f1 = std::bind(add,10,20);// 指定f1的类型：返回值为int的无参函数（因为参数已经绑定好了10，与20）
	cout << f1() << endl;
	std::function<int(int)> f2 = std::bind(add,10,std::placeholders::_1); // 指定f2的类型：返回值为int,形参也为int（因为参数已经绑定好了10，与20）
	cout << f2(30) << endl;
	Example e;
	f1 = std::bind(&Example::add, &e, 8123,20);
	cout << f1() << endl;
	std::function<int(Example*,int)> f4 = std::bind(&Example::add,std::placeholders::_1, 333, std::placeholders::_2); //  指定f4的类型：返回值为int,形参为Example*和int
	cout << f4(&e,2) << endl;
	int x=10;
	std::function<void()> f5 = std::bind(print, x, std::cref(x)); // std::cref(x)将x变为1个引用，相当于在x的地址上，解引用拿到X的值
	f5();//输出10,10 
	x=20;
	f5(); // 输出10,20，第1个10因为是值传递，所以相当于第1个参数固定为10，第二个10是const reference，相当于在x的地址上，解引用拿到X的值
}
int main(){
	test2();
	return 0;
}
