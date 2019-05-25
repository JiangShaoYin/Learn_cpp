 
 /// @file    RAII.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-24 14:00:18
 
#include <memory> 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::weak_ptr;
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
	weak_ptr<Point> wp;
	{
		shared_ptr<Point> sp(new Point(2,3));
		wp = sp;
			cout << sp.use_count() << endl;
		shared_ptr<Point> p2 = wp.lock();
		if(p2) {
			cout << "存活" << endl;	
			cout << sp.use_count() << endl;
			p2->print();
		}
		else
			cout << "expired" << endl;
	}
	shared_ptr<Point> p2 = wp.lock();
		if(p2)
			cout << "存活" << endl;	
		else
			cout << "expired" << endl;
}


int main(){
	test1();
	return 0;
}
