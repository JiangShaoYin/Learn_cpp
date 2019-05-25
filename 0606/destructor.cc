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
		Point(const )


		~Point(){
			cout<<"this is a destructed funtion"<<endl;
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
	

	void test(){
		
	}

int main(){
	Point point(666,777);
	point.print();
	return 0;
}
