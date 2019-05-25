#include "observer.h" 
#include <memory>
using std::unique_ptr;
 
 
void test1() { 
	unique_ptr<Subject> sub(new ConcreteSubject());
	unique_ptr<Observer> obj1(new ConcreteObserver(sub.get()));	
	unique_ptr<Observer> obj2(new ConcreteObserver(sub.get()));	
	unique_ptr<Observer> obj3(new ConcreteObserver(sub.get()));	
	unique_ptr<Observer> obj4(new ConcreteObserver(sub.get()));	

cout << obj1.get() << " "
	 << obj2.get() << " "
	 << obj3.get() << " "
	 << obj4.get() << " " << endl;


	sub->attach(obj1.get());
	sub->attach(obj2.get());
	sub->attach(obj3.get());
	sub->attach(obj4.get());

	sub->set_state(123);
	cout << endl;
	sub->detach(obj1.get());
	sub->set_state(2222);

	
} 
 
int main(){
		test1();
		return 0;
}

