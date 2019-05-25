 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-06 11:42:49
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		_TotalPrice+=_price;
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);
	}
	void print() {
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}
	void TotalPrice(){
		cout<<_TotalPrice<<endl;
	}
	//主要功能：做清理工作, 清理其数据成员中有申请资源的
	~Computer()
	{//必须显式提供析构函数
		delete [] _brand;
		_brand = NULL;
		cout << "~Computer()" << endl;
	}
private:
	char * _brand;
	float _price;
	static float _TotalPrice;
};
float Computer::_TotalPrice=0;

void test1() 
{
	Computer com1("Dell", 6666);//栈对象
	com1.print();
	com1.TotalPrice();
	Computer com3("IBM",13999);
	com3.print();
	com3.TotalPrice();
}

int main(void)
{
	//test0();
	test1();

	return 0;
}
