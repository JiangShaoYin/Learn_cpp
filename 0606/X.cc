 ///
 /// @file    point.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 19:30:36
 
 
#include <iostream>
using std::cout;
using std::endl;
 
class X{
	public:
	X(int ix)
		:x(ix)
		,y(x)
		{
			cout<<"this is constructed function"<<endl;
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
//	Point p;
//	p.print();
	X point(666);
	point.print();
	return 0;
	}
