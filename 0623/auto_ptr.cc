 
 /// @file    RAII.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-24 14:00:18
 
#include <memory> 
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::auto_ptr;

class Point{
	public:
		Point(int x, int y)
		:_x(x)
		,_y(y) {}
		void print() {
			cout << _x << " "
			 	 << _y << endl;
		}
	private:
		int _x;
		int _y;
};
void test1() {
	auto_ptr<Point> p1(new Point(1,2));
	p1->print();
	auto_ptr<Point> p2 = p1;
	p2->print();
	p1->print();


	
}



int main(){
	test1();
	return 0;
}
