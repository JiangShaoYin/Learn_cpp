 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 09:40:14
 ///
 
#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

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

	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
private:
	double _dreal;
	double _dimag;
};

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	if(rhs._dreal == 0 && rhs._dimag != 0)
		os << rhs._dimag << "i";
	else {
		os << rhs._dreal;
		if(rhs._dimag > 0)
			os << " + " << rhs._dimag << " i";
		else if (rhs._dimag < 0)
			os << " - " << rhs._dimag * (-1) << " i";
	}
	return os;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0, int=0)" << endl;
	}


	//由自定义类型向其他类型进行转换
	//
	//类型转换函数
	//1. 必须是成员函数
	//2. 没有返回值类型
	//3. 在函数体内必须用return 语句以传值方式返回一个目标类型的变量(对象)
	//4. 没有形参
	//5. 一般情况下，不要使用它， 因为它违反了常规思维方式

	operator int()
	{	
		cout << "operator int()" << endl;
		return _ix;	
	}

	operator double()
	{	
		cout << "operator double()" << endl;
		return _ix * _iy;	
	}

	operator Complex()
	{
		cout << "operator Complex()" << endl;
		return Complex(_ix, _iy);
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

 
int main(void)
{
	Point pt1(1, 2);
	
	int x = pt1;
	cout << "x = " << x << endl;

	double dvalue = pt1;
	cout << "dvalue = " << dvalue << endl;

	Complex cx = pt1;
	cout << "cx = " << cx << endl;

	return 0;
}
