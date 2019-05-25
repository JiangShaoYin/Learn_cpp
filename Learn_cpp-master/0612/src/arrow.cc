 ///
 /// @file    arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 16:03:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Data
{
public:
	Data(){	cout << "Data()" << endl;}
	~Data() {	cout << "~Data()" << endl;	}
	int length() 
	{
		return 5;
	}
};

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{
		cout << "DataPtr()" << endl;
	}

	//指针访问运算符
	Data * operator->()
	{
		return _pData;
	}

	//解引用运算符
	Data & operator*()
	{
		return *_pData;
	}

	~DataPtr()
	{
		cout << "~DataPtr()" << endl;
		delete _pData;
	}
private:
	Data * _pData;
};


class ThirdLayer
{
public:
	ThirdLayer()
	{
		cout << "ThirdLayer()" << endl;
	}

	DataPtr & operator->()
	{
		return _dp;
	}

	~ThirdLayer()
	{
		cout << "~ThirdLayer()" << endl;
	}

private:
	DataPtr _dp;
};
 
int main(void)
{
	DataPtr dp;
	cout << dp->length() << endl;
	cout << (dp.operator->())->length() <<endl;
	cout << endl;

	cout << (*dp).length() << endl;

	ThirdLayer tl;
	cout << tl->length() << endl;
	cout << ((tl.operator->()).operator->())->length() << endl;

	return 0;
}
