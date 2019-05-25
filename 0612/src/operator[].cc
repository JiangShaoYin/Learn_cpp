 ///
 /// @file    operator[].cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 14:40:30
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	CharArray(int size)
	: _size(size)
	, _data(new char[_size]())
	{
		cout << "CharArray(int)" << endl;
	}

	char & operator[](size_t idx)
	{
		cout << "char & operator[](size_t)" << endl;
		static char nullchar = '\0';
		if(idx >= _size)
			return nullchar;
		return _data[idx];
	}

	void print() const
	{
		cout << _data << endl;
	}

	size_t size() const {	return _size;	}
	

	~CharArray()
	{
		cout << "~CharArray()" << endl;
		delete [] _data;
	}
private:
	size_t _size;
	char * _data;
};
 
int main(void)
{
	const char * str = "hello,world";
	size_t length = strlen(str) + 1;
	CharArray carr(length);

	for(size_t idx = 0; idx != length; ++idx)
	{
		carr[idx] = str[idx];
	}

	for(size_t idx = 0; idx < carr.size(); ++idx)
	{
		cout << carr[idx];
	}

	//carr.print();
	return 0;
}
