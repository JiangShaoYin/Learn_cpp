 ///
 /// @file    Point.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-07 15:03:21
 
 
#include <iostream>
using std::cout;
using std::endl;
class Point{
	public:
		Point()
			:_ix(0)
			,_iy(0)
		{}
		Point(int x,const int y)
			:_ix(x)
			,_iy(y)
		{
			cout<<"Point(int x,int y)"<<endl;
		}
		void print(){
			cout << _ix
			   	<< "," 
				<< _iy ;
		}
	private:
		const int _ix;
		const int _iy;
};
class Line{
	public:
		Line(int x1,int y1,int x2,int y2)
		:_p1()
		,_p2()
		{
			_p1.print();
			cout<<"-->";
			_p2.print();
			cout<<endl;
		}
	private:
		Point _p1;
		Point _p2;

};
int main(){
	Line line(1,2,3,4);
	return 0;
}
