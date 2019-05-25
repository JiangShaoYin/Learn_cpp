 
 /// @file    RAII.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-24 14:00:18
 
#include <memory> 
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::ostream;

class Point{
	public:
		Point(int x, int y)
		:_x(x)
		,_y(y) {}
		void print() {
			cout << _x << " "
			 	 << _y << endl;
		}
	friend ostream & operator<<(ostream & os,const Point & rhs) {
		os << rhs._x << " " << rhs._y;
		return os;
	}
	private:
		int _x;
		int _y;
};

void test1() {
	Point *p = new Point(1,2);
	shared_ptr<Point> p1(p);
{
	shared_ptr<Point> p2(p1);
//	cout << p1.use_count() << endl;
//	cout << p1.use_count() << endl;
	cout << *p1 << endl;
	cout << p1.get() << endl;
	cout << p2.get() << endl;
	cout << endl;
	cout << p1.use_count() << endl;
}
	cout << p1.use_count() << endl;
/*	shared_ptr<int> p2 = get_value();
	cout << *p2 << endl;
	vector<shared_ptr<int>> vec;
	vec.push_back(std::move(p2));
	
	p2.reset(new int(333));
	cout << *p2 << endl;	
	
	cout << p2.get() << endl;
*/
}

int main(){
	test1();
	return 0;
}
