 ///
 /// @file    queue2.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-11 10:49:56
 
 
#include <iostream>
using std::cout;
using std::endl;
class Queue{
	public:
		Queue(int size = 10)
		:arr(new int[size])
		,_front(0)
		,_rear(0)
		,_size(_size)
		{
			cout << "Queue(int size = 10)" << endl;
		}
		bool empty(){
			return _front == _rear;
		}
		bool full(){
			return _front == (_rear+1)%_size;
		}
		void push(int x){
			if(!full()){
				_arr[_rear++] = x;
				_rear %=_size;
			}
			else
				cout << "queue is full !!!do not PUSH" << endl;
		}
		void pop(){
			if(!empty()){
				_front++;
				_front %= _size;
			}
			else
				cout << "queue is empty,do not POP!!!" endl;
		}
		void front(){
		
		}

	private 
		int _front,_rear,_size;
		int _arr[];
}; 
 
 
int main(){

	return 0;
}
