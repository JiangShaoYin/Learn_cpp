 ///
 /// @file    Point.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-07 15:03:21
 
 
#include <iostream>
using std::cout;
using std::endl;
class Point{
	public:
/*		Point & operator = (const Point & rhs){
			_ix=rhs._ix;
			_iy=rhs._iy;
			cout<<"Point & operator=(const Point & rhs)"<<endl;
			return *this;
		}
*/		
		Point()
			:_ix(0)
			,_iy(0)
		{}
		Point(int x,const int y)
			:_ix(x)
			,_iy(y)
			,_ref(x)
		{
			cout<<"Point(int x,int y)"<<endl;
		}
		void print(){
			cout << _ix
			   	<< "," 
				<< _iy << endl ;
		}
	private:
		const int _ix;
		const int _iy;
		int _ref;
};
 
int main(){
	Point A(2,3);
	A.print();
	return 0;
}
