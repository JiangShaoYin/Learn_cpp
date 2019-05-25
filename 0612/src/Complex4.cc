 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 10:10:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{}

	void display() {
		cout << _dreal << " + " << _dimag << "i" << endl;
	}

	//成员函数的形式
	Complex operator+(const Complex & rhs)
	{
		return Complex(_dreal + rhs._dreal,
				       _dimag + rhs._dimag);
	}

private:
	double _dreal;
	double _dimag;
};

 
int main(void)
{
	Complex c1(1, 2);
	Complex c2(3, 4);

	Complex c3 = c1 + c2;
	c3.display();

	Complex c4 = c1 + 5;// c1.operator+(5);
	c4.display();

	Complex c5 = 5 + c1;//operator+(5, c1);
	c5.display();

	return 0;
}
