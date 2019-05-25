 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 09:40:14
 ///
 
#include <math.h>

#include <iostream>
using std::cout;
using std::endl;


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

#if 0
	operator int()
	{	
		cout << "operator int()" << endl;
		return _ix;	
	}
#endif

	operator double()
	{	
		cout << "operator double()" << endl;
		return _ix * _iy;	
	}

	//friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

#if 0
std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
#endif

 
int main(void)
{
	Point pt1(1, 2);
	cout << "pt1 = " << pt1 << endl;
	
	//int x = pt1;
	//cout << "x = " << x << endl;

	double dvalue = pt1;
	cout << "dvalue = " << dvalue << endl;

	return 0;
}
