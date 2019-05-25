 ///
 /// @file    Point2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 09:40:14
 ///
 
#include <math.h>

#include <iostream>
using std::cout;
using std::endl;


class Point;//类的前向声明

class Line
{
public:
	float distance(const Point & lhs, const Point & rhs);
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0, int=0)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
	//友元之成员函数
	friend float Line::distance(const Point & lhs, const Point & rhs);

private:
	int _ix;
	int _iy;
};


#if 0
float distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs.getX() - rhs.getX()) * (lhs.getX() - rhs.getX()) + 
				(lhs.getY() - rhs.getY()) * (lhs.getY() - rhs.getY()));
}
#endif
 
float Line::distance(const Point & lhs, const Point & rhs)
{
	return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
				(lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

int main(void)
{
	Point pt1(1, 2);
	Point pt2(3, 4);

	Line line;
	cout << "pt1和pt2之间的距离: " << line.distance(pt1, pt2) << endl;

	return 0;
}
