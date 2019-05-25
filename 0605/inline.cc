 ///
 /// @file    inline.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 23:25:20
 
#include "inline.h" 
#include "inline.h" 
#include "inline.h" 
#include <iostream>
using std::cout;
using std::endl;

inline 
int multiply(int x,int y){
	return x*y;
}
inline int max(int x,int y){
	return x>y?x:y;
}

int main(){
	int a=3,b=4,c=5;
	cout<<" "<<multiply(a+b,c)<<endl;
	cout<<" "<<max(a+b,c)<<endl;
	cout<<" "<<add(a+b,c)<<endl;

	return 0;
}
