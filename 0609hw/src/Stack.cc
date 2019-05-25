 ///
 /// @file    Stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 10:02:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Stack
{
public:
	explicit
	Stack(int size = 10)
	: _size(size)
	, _top(-1)
	, _arr(new int[_size]())
	{
		cout << "Stack()" << endl;
	}
	
	bool empty() const
	{
		return _top == -1;
	}

	bool full() const
	{
		return _top == (_size - 1);
	}

	void push(int number)
	{
		if(!full())
			_arr[++_top] = number;//
		else
			cout << "stack is full, cannot push any more" << endl;
	}

	void pop()
	{
		if(!empty())
			--_top;
		else
			cout << "stack is empty " << endl;
	}

	int top()
	{
		return _arr[_top];
	}

private:
	int _size;
	int _top;
	int  * _arr;
};
 
int main(void)
{
	Stack stack;
	cout << "此时栈是否为空?" << stack.empty() << endl;
	stack.push(1);
	cout << "此时栈是否为空?" << stack.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		stack.push(idx);
	}
	cout << "此时栈是否已满?" << stack.full() << endl;

	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "此时栈是否为空?" << stack.empty() << endl;
	return 0;
}
