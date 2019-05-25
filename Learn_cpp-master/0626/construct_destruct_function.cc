			
#include <iostream>
using std::cout;
using std::endl;
class Base0{
	public:  Base0() {	cout << "Base0()" << endl;	}
					~Base0() {	cout << "~Base0()" << endl;	}
				virtual void func1() {	cout << "Base0::func1()" << endl;	}
					virtual void func2() {	cout << "Base0::func2()" << endl;	}
};//end of Base0

class Base1
: public Base0
{
	public:
//在构造函数或析构函数中调用虚函数，采用的是静态联编
	Base1()	: Base0()
		{	cout << " Base1()" << endl;			func1();	}
	~Base1() {	cout << "~Base1()" << endl;			func2();}
	#if 1
	virtual	void func1() {	cout << "Base1::func1()" << endl;	}
	virtual void func2() {	cout << "Base1::func2()" << endl;	}
	#endif
	};//end of Base1

class Derived
	: public Base1
	{
	public:
		Derived() 
				: Base1()	{		cout << "Derived()" << endl;	}
		~Derived() {		cout << "~Derived()" << endl;	}
	virtual void func1() {	cout << "Derived::func1()" << endl;	}
	virtual void func2() {	cout << "Derived::func2()" << endl;	}	
		};

int main(void){
		Derived d;
		return 0;
	}

