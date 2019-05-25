 ///
 /// @file    functionCall.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 11:39:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;


int func1(int x, int y)
{
	static int counter = 0;
	cout << "counter = " << counter << endl;

	return x + y;
}

class Foo
{
public:
	Foo()
	: _counter(0)
	{}

	//重载了函数调用运算符的类创建的对象称为函数对象
	//
	//函数对象可以拥有自己的状态  ==> 闭包 ==> lamdba表达式(匿名函数)
	//
	int operator()(int x, int y)
	{
		++_counter;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		++_counter;
		return x * y * z;
	}

	int getCounter() const {	return _counter;	}
private:
	int _counter; 
};

int main(void)
{
	cout << "1 + 2 = " << func1(1, 2) << endl;

	Foo foo;
	cout << "1 + 2 = " << foo(1, 2) << endl;//函数对象
	cout << "3 * 4 * 5 = " << foo(3, 4, 5) << endl;

	cout << "foo对象被调用了" << foo.getCounter() << "次"<< endl;

	Foo bar;

	return 0;
}
