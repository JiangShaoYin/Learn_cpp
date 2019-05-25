 ///
 /// @file    singleton1.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-13 12:58:45
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton{
	public:
		static Singleton* getInstance(){
			if(!_p){
				_p=new Singleton();
				cout << "getInstance()" << endl;
			}
				return _p;
		}
	private:
		Singleton(){};
		~Singleton(){};
		class AutoRelease{
			public:
				AutoRelease(){
					cout << "AutoRelease()" << endl;
				}
				~AutoRelease(){
					cout << "~AutoRelease" << endl;
					delete _p;
				}
		};
	private:
		static Singleton *_p;
		static AutoRelease _auto;
};
Singleton* Singleton::_p=NULL; 
Singleton::AutoRelease Singleton::_auto;
int main(){
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	printf("%p\n",p1);
	printf("%p\n",p2);
	
	return 0;
}
