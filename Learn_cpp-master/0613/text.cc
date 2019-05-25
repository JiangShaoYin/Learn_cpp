 
 /// @file    text.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-14 21:50:56
 
 
#include <iostream>
using std::cout;
using std::cout;
using std::endl;
using std::ostream;
class A{
	public:
		A(int x)
			:_x(x){}
	friend	ostream & operator<<(ostream & os,A & rhs);
		
	private:int _x;
}; 
ostream & operator<<(ostream & os,A & rhs){
	os << rhs._x;
	return os;
}
 
 
int main(){
	A test(123);
	cout << test << endl;

	return 0;
}
