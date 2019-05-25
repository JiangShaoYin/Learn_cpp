 ///
 /// @file    example.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-12 16:41:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int x = 100;
int z = 200;

class Example
{
public:
	Example(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	void print(int x = 0)
	{
		cout << "形参x = " << x << endl;
		cout << "数据成员x = " << this->x << endl;
		cout << "数据成员x = " << Example::x << endl;
		cout << "全局变量x = " << ::x << endl;
	}
private:
	int x;
	int y;
};
 
int main(void)
{
	Example e;
	e.print(10);

	return 0;
}
