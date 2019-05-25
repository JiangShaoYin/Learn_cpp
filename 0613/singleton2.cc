 ///
 /// @file    singleton1.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-13 12:58:45
#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton{
	public:
		static Singleton* getInstance(){
			if(!_p){
				pthread_once(&_once,init);
			}
				return _p;
		}
		static void init(){
			_p=new Singleton();
			atexit(destory);
			cout << "atexit(destory)" << endl;
		}
		static void destory(){
			if(_p)
				delete _p;
			cout << "destory" << endl;
		}
	private:			
		static Singleton *_p;
		static pthread_once_t _once;
};
Singleton* Singleton::_p=NULL; 
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

int main(){
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	printf("%p\n",p1);
	printf("%p\n",p2);
	
	return 0;
}
