 
 /// @file    point3d.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 12:54:50
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Point
{
	public:
		Point(int ix, int iy)
			: _ix(ix)
			, _iy(iy)
			{	cout << "Point(int,int)" << endl;	}
		void print() const
			{
				cout << "(" << _ix
					 << "," << _iy
					 << ")" << endl;
			}
		~Point()
			{	cout << "~Point()" << endl;	}
		int getX() const {	return _ix;	}
	protected:
			int getY() const {	return _iy;	}
	private:
			int _ix;
			int _iy;
};

class Point3D
:public Point
{
	public:
		Point3D(int x, int y, int z)
			:Point(x, y)
			,_z(z)
			{	}
		void display() const {
			cout << getX() << ","
				 << getY() << ","
				 << _z	   << endl;
		}
	private:
		int _z;
};



int main(){
	Point3D pt(1,2,3);
	pt.display();
	pt.print();
//	pt.getY();
	pt.getX();
	return 0;
}
