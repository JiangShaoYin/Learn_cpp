 ///
 /// @file    signleton.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-08 19:36:04
 
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;




class Singleton{
	public:
		static Singleton * Getp() {
		if(!p) {
				p = new Singleton();
				cout << "static Singleton * Getp()" << endl;
			}
			return p;
		}
		static void destory() {
			if( p ) delete p;
			cout << "destory" << endl;
		}
	private:
		Singleton(){
			cout << "private Singleton()" << endl;
		}
		~Singleton() {
			cout << "~Singleton()" << endl;
		}
	private:
		static Singleton *p;
};
 
	Singleton *Singleton::p = NULL;
	

int main(){
	Singleton *p1 = Singleton::Getp();
	Singleton *p2 = Singleton::Getp();
	printf("%p\n", p1);
	printf("%p\n", p2);

	Singleton::destory();
//	Singleton::destory();
	return 0;
}
