/// @date    2018-06-27 12:49:26
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
		Base(long base)
			: _base(base)
		{}
		virtual void a() {	cout << "Base::a()" << endl;	}
		virtual void b() {	cout << "Base::b()" << endl;	}
		virtual void c() {	cout << "Base::c()" << endl;	}
	private:
		long _base;	
};//end of Base

class Derived : public Base {
	public:
		Derived(long base, long derived)
			  : Base(base)
			  , _derived(derived)
	{}
		virtual void a() {	cout << "Derived::a()" << endl;	}
		virtual void b() {	cout << "Derived::b()" << endl;	}
		virtual void c() {	cout << "Derived::c()" << endl;	}
	private:
		long _derived;	
};// end of derived

int main(void){
//	证明虚表的存在
//		cout << "sizeof(long) = " << sizeof(long) << endl;
	Derived derived(10, 100);
	typedef void(*Function)();
#if 0
	long * pDerived = (long *)&derived;	
	long * pVtable = (long *)(*pDerived);

	Function f1 = (Function)(pVtable[0]);
	f1();

	f1 = (Function)(pVtable[1]);
	f1();
	f1 = (Function)(pVtable[2]);
	f1();
#endif
#if 1
	long ** p = (long **)&derived;
	long * p1 = (long *)&derived;
//	cout << &p << endl;
	cout << "p = " << p << endl;
	cout << "p1 = " << p1 << endl;
	Function f1 = (Function)p[0][0];
	f1();
	cout << "p[0] = " << p[0] << endl;
	cout << "*p = " << *p << endl;
	cout << "**p = " << **p << endl;
	cout << "p[0][0] = " << p[0][0] << endl;
	cout << "p[0][0] = " << p[0][1] << endl;

#if 0
	f1 = (Function)p[0][1];
	f1();
	f1 = (Function)p[0][2];
	f1();
#endif
//	cout << (long)p[1] << endl;
//	cout << (long)p[2] << endl;
#endif



	return 0;
}
//
