 ///
 /// @file    1.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-07 10:47:18
 
 
#include <iostream>
using std::cout;
using std::endl;
class test{
	public:
		test()
		:_x(0)
		,_y(0){}
		~test(){
			cout<<"析构函数"<<endl;
		}
	private:
		int _x;
		int _y;
};
 
 
int main(){
	test();
	int b(2);
	cout<<b<<endl;
	char c('A');
	cout<<c<<endl;

	return 0;
}
