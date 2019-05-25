 ///
 /// @file    main.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 18:44:57
 
#include "computer.h" 
#include <iostream>
using std::cout;
using std::endl;
 
 
 
int main(){
	computer A;
	A.setbrand("dell");
	A.setprice(9999);
	A.print();
//	A._price=10;
	return 0;
}
