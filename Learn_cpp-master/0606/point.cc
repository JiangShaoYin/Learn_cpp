 ///
 /// @file    point.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 19:30:36
 
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point{
	public:
		Point(){
			cout<<"this is constructed function"<<endl;
			x=0;
			y=0;
		}
		Point(int ix,int iy){
			cout<<"this is another constructed function"<<endl;
			x=ix;
			y=iy;
		}
	void print(){
			cout << x  << "," << y << endl;
		}
	private:
		int x;
		int y;
};
 
int main(){
	Point p;
	p.print();
	Point point(666,777);
	point.print();
	return 0;
}
