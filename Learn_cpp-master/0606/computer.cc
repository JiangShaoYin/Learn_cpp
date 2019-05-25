 ///
 /// @file    func.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 18:37:11
 
#include "computer.h" 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
 
void computer::setbrand(const char * brand){
	strcpy(_brand,brand);
} 

void computer::setprice(float price){
	_price=price;
}

void computer::print(){
	cout<<_brand <<endl;
	cout<<_price <<endl;
}
 
