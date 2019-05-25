 
 /// @file    RAII.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-24 14:00:18
 
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <class T>
class RAII{
	public:
		RAII(T * p)
			:_p(p){}
		T * operator->() {
			return _p;	
		}
		T & operator*() {
			return *_p;
		}
		~RAII() {
		if(_p) {
			delete _p;
			cout << "~RAII" << endl;
		}
		}
	private:
		T *_p;
};
 
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
 
int main(){
	RAII<int> tmp1(new int(123));
	cout << *tmp1 << endl;

	RAII<Point> tmp2(new Point(1,2));
	tmp2->print();
	(*tmp2).print();
	return 0;
}
