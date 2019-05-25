 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 10:10:03
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;

//  -1 能不能开方 ？
//  虚数  i ^2 = -1 
//
//  欧拉公式

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{}

	void display() {
		if(_dreal == 0 && _dimag != 0)
			cout << _dimag << "i" << endl;
		else {
			cout << _dreal;
			if(_dimag > 0)
				cout << " + " << _dimag << " i" << endl;
			else if (_dimag < 0)
				cout << " - " << _dimag * (-1) << " i" << endl;
			else
				cout << endl;
		}
	}

	//推荐以成员函数形式进行重载
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}


	//for(int idx = 0; idx != 10; ++idx)
	//{
	//  ....
	//}

	//前置++，推荐以成员函数形式进行重载
	Complex & operator++()
	{
		cout << "Complex & operator++()" << endl;
		++_dreal;
		++_dimag;
		return *this;
	}

	//后置++
	Complex operator++(int) //int是为了与前置++进行区分，是一个标记
	{
		cout << "Complex operator++(int)" << endl;
		Complex temp(*this);	
		++_dreal;
		++_dimag;
		return temp;
	}

	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	friend bool operator < (const Complex & lhs, const Complex & rhs);

	friend std::istream & operator>>(std::istream & is, Complex & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);


	//输入输出流运算符不能是成员函数进行重载,
	//因为输入输出流的第一个形参必须是流对象，
	//而成员函数的第一个形参是隐含的this指针，
	//这就导致了冲突
	//operator<<()

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

void readDouble(std::istream & is, double & value)
{
	cout << "pls input a number:";
	while(is >> value, !is.eof())
	{
		if(is.bad())
		{
			cout << "is has corrupted!" << endl;
			return;
		} else if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a number:";
		} else
			break;
	}
}
std::istream & operator>>(std::istream & is, Complex & rhs)
{
	readDouble(is, rhs._dreal);
	readDouble(is, rhs._dimag);
	//is >> rhs._dreal;
	//is >> rhs._dimag;
	return is;
}

//友元函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

bool operator < (const Complex & lhs, const Complex & rhs)
{
	return lhs._dreal < rhs._dreal;
}

 
int test0(void)
{
	Complex c1(1, -2);
	c1.display();
	Complex c2(3, 4);
	c2.display();

	Complex c3 = c1 + c2;
	c3.display();
	Complex c4(0, 0);
	c4.display();
	Complex c5(0, -1);
	c5.display();

	return 0;
}

//Complex & operator+=(Complex & lhs, const Complex & rhs);

void test1(void)
{
	int a = 3, b = 4;
	a += b;// a = a + b

	++a;//前置++  表达式的值与a变化之后的值是一样的
	a++;//后置++

	Complex c1(1, -2);
	cout << "c1 = ";
	c1.display();

	cout << "++c1 = ";
	(++c1).display();
	cout << "c1 = ";
	c1.display();

	cout << endl;
	cout << "c1++ = ";
	(c1++).display();
	cout << "c1 = ";
	c1.display();
	
}

void test2(void)
{
	Complex c1(1, -2);
	c1.display();
	Complex c2 = c1 + 5;//operator+(c1, 5);// 存在隐式转换
	c2.display();

	Complex c3 = 5 + c1;//operator+(5, c1);
	c3.display();
}

void test3(void)
{
	Complex c1(1, -2);
	cout << "c1 = " << c1 << endl;
}

void test4(void)
{
	Complex c1;
	Complex c2;
	(std::cin >> c1) >> c2 ;
	cout << "c1 = " << c2 << endl;
}


int main(void)
{
	//test2();
	//test1();
	//test3();
	test4();
	return 0;
}
