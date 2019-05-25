 
 /// @file    Stackcomplate.cc
/// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-15 09:32:27
 
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
 
template <class T,int size =10>
class Queue{
	public:
		Queue();
		Queue(T t);
		~Queue();
		bool empty() ;
		bool full();
		void push(T const & t);
		void pop();
		void print();
		T  top();
	private:
		int _front;
		int _rear;
		T *_base;
};

template <class T,int size>
Queue<T,size>::Queue()
			   :_front(0)
			   ,_rear(0)
			   ,_base(new T[size]){
				   cout << "Queue();" << endl;
			   }

template <class T,int size>
Queue<T,size>::~Queue(){delete [] _base; }

template <class T,int size>
bool Queue<T,size>::empty(){
		return _front ==_rear;
}

template <class T,int size>
bool Queue<T,size>::full(){
	return (_rear-_front+size)%size==(size-1);
}
 
template <class T,int size>
void Queue<T,size>::push(const T & t){
	if(!full()){
		_base[_rear]=t;
		++_rear%=size;
	}
	else
		cout << "queue is full" << endl;
}

template <class T,int size>
void Queue<T,size>::pop(){
	if(!empty()){
		++_front%=size;
	}
}

template <class T,int size>
T Queue<T,size>::top(){
	if(!empty()){
		return _base[_front];
	}
}

template <class T,int size>
void  Queue<T,size>::print(){
	cout << "front= " << _front
		 << "rear="  << _rear << endl;
}


void test1(){
	Queue<int> queue;
	cout << "queue.empty() " << queue.empty() << endl;
	cout << "queue.full() " << queue.full() << endl;
//		queue.push(1);
//		cout << queue.top() << endl;
	for(int i=0;i<12;i++){
		cout << i <<endl;

	cout << "before push,queue.full() " << queue.full() << endl;
		queue.push(i);
		queue.print();
	cout << "after push,queue.full() " << queue.full() << endl;
	cout << endl;
	}
	cout << "hahha" << endl;
}

void test2(){
	Queue<string> queue;
	queue.push("hahha");
	cout << queue.top() << endl;
	queue.pop();
	for(int idx=0;idx<12;++idx){
	string str(3,'A'+idx);
		queue.push(str);
	}
	while(!queue.empty()){
		cout << queue.top() << endl;
		queue.pop();
	}
}
 

int main(){
//	test1();
	test2();
	return 0;
}

