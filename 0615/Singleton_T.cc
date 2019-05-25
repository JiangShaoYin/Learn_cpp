#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Point{
	public:
		Point(int x,int y)
			:_x(x)
			,_y(y){	}
		void print() {
			cout << "(" << _x
				 << "," << _y
				 << ")" << endl;
				}
	private:
			int _x;
			int _y;
};
class Computer{
	public:
		Computer(string str,int price)
			:_str(str)
			,_price(price) {}
		void print() const {
			cout << _str << " "
				 << _price << endl;
		}
	private:
		string _str;
		int _price;
};

template <typename T>
class Singleton{
		class AutoRelease{
				public:
					AutoRelease(){}
					~AutoRelease() {
					if(_pInstance)
						delete _pInstance;
					cout << "~AutoRelease" << endl;
					}
					};
		  public:
			  template <typename ...Args>
			  static T* getInstance(Args ...args) {
				  if(!_pInstance) {
					  _auto;
					  _pInstance = new T(args...);
					  }
					  return _pInstance;
				  }
		 private:
				  Singleton(){}
				  ~Singleton(){}
		 private:
			static T * _pInstance;
			static AutoRelease _auto;
};	

template <typename T>
T* Singleton<T>::_pInstance = NULL;

template <typename T>
class Singleton<T>::AutoRelease Singleton<T>::_auto;  //模板的声明，前面class表明
//表明AutoRelease是类对象


int main() {
		Point *p1 = Singleton<Point>::getInstance(2,3);
		Point *p2 = Singleton<Point>::getInstance(3,4);
		Computer *p3 = Singleton<Computer>::getInstance("DELL",9999);
		Computer *p4 = Singleton<Computer>::getInstance("IBM",19999);
		p1->print();
		p2->print();
		printf("%p\n",p1);	
		printf("%p\n",p2);	
		p3->print();
		p4->print();
		printf("%p\n",p3);	
		printf("%p\n",p4);	
}
