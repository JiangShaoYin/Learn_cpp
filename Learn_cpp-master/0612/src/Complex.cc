 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 10:10:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//  -1 能不能开方 ？
//  虚数  i ^2 = -1 
//
//  欧拉公式

class Complex
{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{}

	void display() {
		cout << _dreal << " + " << _dimag << "i" << endl;
	}

private:
	double _dreal;
	double _dimag;
};


//运算符重载的功能不能针对于内置类型数据
//只能作用于自定义类类型和枚举类型
int operator+(int x, int y)
{
	return x - y;
}

 
int main(void)
{
	Complex c1(1, 2);
	Complex c2(3, 4);

	Complex c3 = c1 + c2;

	return 0;
}
