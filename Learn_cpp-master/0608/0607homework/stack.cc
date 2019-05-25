 ///
 /// @file    0607homewoek.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-10 11:47:28
#include <string.h> 
#include <vector> 
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

class Stack{
	public:
		Stack(){
			_top=-1;
			memset(_num,0,sizeof(_num));
		}
		void push(int x){
			if(_top==9){
				cout << "stack is full!!!" << endl;
				return;
			}
			_num[++_top]=x;
			cout << "push num = " << x << endl;
		}
		void pop(){
			_top--;
		}
		bool full(){
			return _top==10?true:false;
		}
		bool empty(){
			return _top==-1?true:false;
		}
		int top(){
			return _num[_top];
		}
	private:
		int _num[10];
		int _top;
};

void test(){
	Stack stack;
	stack.push(12);
	cout << stack.top() << endl;
	stack.pop();
	cout << stack.full() << endl;
	cout << stack.empty() << endl;
	cout << stack.top() << endl;
}

int main(){
	test();
	return 0;
}
