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

	double getReal() const {	return _dreal;	}
	double getImage() const {	return _dimag;	}

private:
	double _dreal;
	double _dimag;
};
int operator+(int,int);
//普通函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs.getReal() + rhs.getReal(),
				   lhs.getImage() + rhs.getImage());
}

 
int main(void)
{
	Complex c1(1, 2);
	Complex c2(3, 4);

	Complex c3 = c1 + c2;
	c3.display();

	return 0;
}
