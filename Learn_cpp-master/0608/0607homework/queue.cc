 ///
 /// @file    queue.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-10 12:29:38
 
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
 
class Queue{
	public:
		Queue()
			:_front(-1)
			,_rear(-1){
				memset(_num,-1,sizeof(_num));
			}
		void push(int x){
				_num[++_rear] = x;			
		}
		void pop(){
			cout << "void pop()" <<endl << endl;
			_front++;
		}
		int front(){
			if(!empty())
				return _num[++_front];
			else
				cout << "empty queue!!!" << endl;
		}
		void show(){
			cout << "_front = " <<_front
				 << ",_rear = " << _rear <<endl;
		}
		bool full(){
			return _rear==9?true:false;
		}
		bool empty(){
			cout << "bool empty()" << endl << endl;
			return _rear >=_front?true:false;
		}

	private:
		int _num[10];
		int _front,_rear;
}; 
 void test(){
	 Queue queue;
//	 queue.pop();
//	 queue.show();
	 queue.push(1);
	 cout << queue.full() << endl;
//	 queue.pop();
	 queue.show();
	 cout << queue.empty() << endl;
 	 cout << "front = " << queue.front() << endl;
	 queue.pop();
	 queue.show();
	 queue.front();

 }
int main(){
	test();
	return 0;
}
