 ///
 /// @file    computer.h
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 18:31:54
#include <iostream>
#include <string.h>
using namespace std;

class  computer{
	public:
		computer(const char*brand,float price)
			:_brand(new char[strlen(brand)+1])
			,_price(price)
			{
				strcpy(_brand,brand);
				cout<<"constructed function"<<endl;
			}
		computer(const computer & rhs)
			:_brand(new char[strlen(rhs._brand)+1]())
			,_price(rhs._price)
		{
			strcpy(_brand,rhs._brand);
			cout<<"computer(const computer & rhs)"<<endl;
		}
		
		void print(){
			cout<<_brand<<endl;
			cout<<_price<<endl;
		}
		~computer(){
			delete [] _brand;
			_brand=NULL;
			cout<<"destructor"<<endl;
		}
	private:
		char * _brand;
		float _price;
};

computer  func(){
	computer A("ACER",3999);
	A.print();
//	return A;
}


int main(){
	computer A("IBM",15999);
	A.print();
			cout<<endl;
#if 0
	computer B(A);
	B.print();
			cout<<endl;
	computer C=A;
	C.print();
			cout<<endl;
	func(A);
#endif
	func();
	return 0;
}
