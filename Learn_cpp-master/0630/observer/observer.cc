#include "observer.h"
#include <algorithm>

ConcreteObserver::ConcreteObserver(Subject *ob)
	:_subject(ob), _state(-1) {
				cout << "ConcreteObserver()" << endl;
	}
void ConcreteObserver::update() {
		if(_state != _subject->get_state()) {
			_state = _subject->get_state();	
			cout << "udate value " << _state << endl;
		}
}
//---------------------------------------------------------------
void Subject::attach(Observer * ob) {
		auto iter = std::find(_oblist.begin(), _oblist.end(), ob);
			if(iter == _oblist.end())
					_oblist.push_back(ob);
			else
				cout << "attach error" << endl;
}
void Subject::detach(Observer *ob) {
		auto iter = std::find(_oblist.begin(), _oblist.end(), ob);
			if(iter != _oblist.end())
					_oblist.erase(iter);
}
void Subject::notify() {
		for(auto & ob :_oblist){
				ob->update();
		}
}
int Subject::get_state() {return _state;}
void Subject::set_state(int state) {_state = state;}

void ConcreteSubject::set_state(int state) {
		_state = state;
			notify();
}



