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
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);
	}

	//系统提供的复制构造函数 已经不再满足需求
#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand) // 浅拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
	}
#endif

	//必须要显式提供自己的复制构造函数
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer&)" << endl;
	}

	Computer & operator=(const Computer & rhs){
	if(this!=&rhs){
		delete [] _brand;
		_brand=new char[strlen(rhs._brand)+1];
		strcpy(_brand,rhs._brand);
	    _price=rhs._price;
		cout<<"Computer & operator=(const Computer & rhs)"<<endl;
		return *this;
	}
	}


	void print() {
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
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
};

//Computer com2("Mac", 8888);//当被销毁时，会自动调用析构函数

//static Computer com3("HASEE", 5555);
 
int test0(void)
{
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	Computer com1("Dell", 6666);//栈对象
	com1.print();
	com1.~Computer();//析构函数可以主动调用，但不建议这样使用

	Computer * pc = new Computer("ASUS", 7777);
	pc->print();
	pc->~Computer();

	delete pc;//堆对象，只有当使用delete表达式，才会自动调用析构函数

	return 0;
}

void func(Computer com) //形参要进行初始化  Computer com = com1
{
	com.print();
}

Computer func1()
{
	Computer com3("HASEE", 5555);
	com3.print();
	return com3;
}

void test1(void)
{
	Computer com1("Dell", 6666);//栈对象
/*	cout << ">> com1:";
	com1.print();

	Computer com2 = com1;//调用Computer的复制构造函数
	cout << " >> com2:";
	com2.print();
	cout << endl;

	func(com1);
	cout << endl;
	func1();
*/
	Computer com3("IBM",13999);
	com3.print();
	com3=com3;
	com3.print();
}

int main(void)
{
	//test0();
	test1();

	return 0;
}
