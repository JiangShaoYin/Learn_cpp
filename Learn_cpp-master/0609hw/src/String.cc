 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 09:47:52
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
public:
	String()
	: _pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
	}

	String & operator=(const String & rhs)
	{
		if(this != &rhs){
			delete [] _pstr;

			_pstr = new char[strlen(rhs._pstr) +1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	void print()
	{
		if(_pstr)
			cout << _pstr << endl;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
private:
char * _pstr;
};
 
int main(void)
{
	String s;
	s.print();

	cout << "......." << endl;

	return 0;
}
