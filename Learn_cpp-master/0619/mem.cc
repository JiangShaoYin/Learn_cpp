 
 /// @file    mem.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-19 22:36:16
 
 
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::for_each;

class Num{ 
	public:
		Num(int val);
		void display();
		bool is_even();
		bool is_primer();
	private:
		int _val;
};

Num::Num(int val)
	:_val(val) {	}
void Num::display(){
	cout << _val << " ";
}
bool Num::is_even(){
	return !(_val%2);
}
bool Num::is_primer() {
	if(_val==1)
		return false;
	for(int idx = 2; idx < _val/2; ++idx) {
		if(_val%idx==0)	
			return false;
	}
	return true;
}


void test() {
	vector<Num> num;
	for(int i=1; i < 20; ++i) {
		num.push_back(i);
	}
	for_each(num.begin(), num.end(), std::mem_fn(&Num::display));
	cout << endl;
	num.erase(remove_if(num.begin(), num.end(), std::mem_fn(&Num::is_even)),
			  num.end());
	for_each(num.begin(), num.end(), std::mem_fn(&Num::display));
	cout << endl;
	num.erase(remove_if(num.begin(), num.end(), std::mem_fn(&Num::is_primer)),
			  num.end());
	for_each(num.begin(), num.end(), std::mem_fn(&Num::display));
	cout << endl;
	
}

int main(){
	test();
	return 0;
}
