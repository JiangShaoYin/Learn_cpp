 ///
 /// @file    Point.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-07 15:03:21
 
 
#include <iostream>
using std::cout;
using std::endl;
class Point{
	public:
		Point & operator = (const Point & rhs){
			_ix = rhs._ix;
			_iy = rhs._iy;
			cout<< "Point & operator=(const Point & rhs)" << endl;
			return *this;
		}
		Point()
			:_ix(0)
			,_iy(0)
		{}
		Point(int x,int y)
			:_ix(x)
			,_iy(y)
		{
			cout<<"Point(int x,int y)"<<endl;
		}
		void print(){
			cout << _ix
			   	<< "," 
				<< _iy << endl ;
		}
	private:
		int _ix;
		int _iy;
};
 
int main(){
	Point A(2,3);
	A.print();
	Point B;
	cout<<endl;
	B=A;
	B.print();
	return 0;
}
