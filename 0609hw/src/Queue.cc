 ///
 /// @file    Queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 10:33:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Queue
{
public:
	Queue(int size = 10)
	: _size(size)
	, _front(0)
	, _rear(0)
	, _base(new int[_size]())
	{
	}

	bool empty() const
	{
		return _front == _rear;
	}
	bool full()const
	{
		return _front == (_rear + 1) % _size;
	}

	void push(int number)
	{
		if(!full())
		{
			_base[_rear++] = number;
			_rear %= _size;
		} else
			cout << "queue is full" << endl;
	}

	void pop()
	{
		if(!empty())
		{
			++_front;
			_front %= _size;
		} else
			cout << "queue is empty" << endl;
	}

	int front() const
	{
		return _base[_front];
	}

	int back() const
	{
		return _base[(_rear - 1 + _size) % _size];
	}

private:
	int _size;
	int _front;
	int _rear;
	int * _base;
};
 
int main(void)
{
	Queue queue;
	cout << "此时queue是否为空?" << queue.empty() << endl;
	queue.push(1);
	cout << "此时queue是否为空?" << queue.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		queue.push(idx);
	}
	cout << "此时queue是否已满?" << queue.full() << endl;

	cout << "此时队头元素是:" << queue.front() << endl;
	cout << "此时队尾元素是:" << queue.back() << endl;

	queue.pop();
	queue.push(11);
	cout << "元素出队，又进队之后:" << endl;
	cout << "此时队头元素是:" << queue.front() << endl;
	cout << "此时队尾元素是:" << queue.back() << endl;

	while(!queue.empty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	cout << "此时queue是否为空?" << queue.empty() << endl;
	return 0;
}
