 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-05 10:36:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int num=10;

namespace A{
	void dispaly(){
		cout<<"this is dispaly of A"<<endl;
	}
}

namespace B{
	void dispaly(){
		cout<<"this is dispaly of B"<<endl;
	}
	int num=20;
	void show_num(int num){
		cout<<"num="<<num<<endl;
	}
}
int main(){
	B::show_num(30);
	B::show_num(B::num);
	B::show_num(::num);
	return 0;
}
