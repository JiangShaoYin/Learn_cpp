 ///
 /// @file    computer.h
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 18:31:54
#include <iostream>
#include <string.h>
using namespace std;

struct  computer{
	public:
		void setbrand(const char * brand){
			strcpy(_brand,brand);
		}
		void setprice(float price){
			_price=price;
		}
		void print(){
			cout<<_brand<<endl;
			cout<<_price<<endl;
		}
		char  _brand[20];
		float _price;
};

int main(){
	computer A;
	A.setbrand("mac");
	A.setprice(12999);
	A.print();
	A._price=129;
	cout<<A._price<<endl;
	return 0;
}
