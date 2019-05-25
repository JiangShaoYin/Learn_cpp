 ///
 /// @file    point.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 19:30:36
 
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point{
	public:
		Point(int ix,int iy){
			cout<<"this is another constructed function"<<endl;
			x=ix;
			y=iy;
		}
		Point()	
			:Point(0,0)                //委托Point(int ix,int iy)进行初始化
		{
			cout<<"point()"<<endl;
		}
		Point(int ix)					   //委托Point(int ix,int iy)进行初始化 
			:Point(ix,0)
		{
			cout<<"point(int x,0)"<<endl;
		}
	void	print(){
			cout << x
			     << ","
				 << y << endl;
		}
	private:
		int x;
		int y;
};
 
int main(){
	Point point(666,777);
	point.print();
	Point point1;
	point1.print();
	Point point2(666);
	point2.print();
	return 0;
}
