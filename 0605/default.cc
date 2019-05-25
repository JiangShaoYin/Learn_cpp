 ///
 /// @file    default.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 20:36:04
 
 
#include <iostream>
using std::cout;
using std::endl;
int add(int x,int y=10);

int add(int x,int y){
	return x+y;
}
int add(int x,int y,int z){
	return x+y+z;
}

int main(){
	int a=3,b=4,c=5;
	add(3);
	cout<<"add(3)="<<add(3)<<endl;
	cout<<"add(3,5,6)="<<add(3,5,6)<<endl;

}
