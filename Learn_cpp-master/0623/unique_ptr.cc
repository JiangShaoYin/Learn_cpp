 /// @file    RAII.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-24 14:00:18
 
#include <memory> 
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::unique_ptr;
using std::vector;

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
unique_ptr<int>  get_value() {
	unique_ptr<int> tmp(new int(100));
	return tmp;
}

void test1() {
	Point *p = new Point(1,2);
	unique_ptr<Point> p1(p);
	cout << p1.get() << endl;
#if 0
	p1->print();
	unique_ptr<int> p2 = get_value();
	cout << *p2 << endl;

	vector<unique_ptr<int>> vec;
	vec.push_back(std::move(p2));
	
	p2.reset(new int(333));
	cout << *p2 << endl;	
	
	cout << p2.get() << endl;
#endif
}



int main(){
	test1();
	return 0;
}
