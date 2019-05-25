 /// @date    2018-06-30 22:44:25

#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::list;
class Subject;

class Observer {
	public:
		Observer() {cout << "Observer()" << endl; }
	virtual void update() = 0; 
	virtual ~Observer() {cout << "~Observer()" << endl;}
};
class ConcreteObserver : public Observer {
	public:
		ConcreteObserver(Subject* ob);
		void update();
		virtual ~ConcreteObserver() {cout << "~ConcreteObserver()" << endl;}
	private:
		Subject *_subject;
		int _state;
};//end of ConcreteObserver


class Subject {
	public:
		Subject() :_state(-1) {cout << "Subject()" << endl;}
		void attach(Observer*);
		void detach(Observer*);
		virtual void notify();
		virtual int get_state();
		virtual void set_state(int state);
		virtual ~Subject() {cout << "~Subject()" << endl;}
	protected:
		list<Observer*> _oblist;
		int _state;
};
class ConcreteSubject : public Subject {
	public:
		ConcreteSubject() {cout << "ConcreteSubject()" << endl;}
		virtual void set_state(int state);
		virtual ~ConcreteSubject() { cout << "~ConcreteSubject" << endl;}
};
#endif
