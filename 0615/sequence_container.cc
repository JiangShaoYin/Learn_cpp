 
 /// @file    sequence_container.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-15 17:54:18
 
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::deque;
using std::string;

template <class Container>
void display(const Container &t){
	class Container::const_iterator cit = t.begin();
	for(;cit!=t.end();++cit){
		cout << *cit << " ";
	}
	cout << endl;
}

void test0(){
	int arr[5]={1,2,3,4,5};	
//	vector<int> num(10,1);
//	list <string> str(10,"AA");
//	deque<int> num3(arr,arr+5);
//	display(num);
//	display(num2);
	vector<int> num2{1,2,3,4,5};
	cout << "num2 capacity: " << num2.capacity() << endl;
//	display(str);
//	display(num3);
	auto cit = num2.begin();
	++cit;
	num2.insert(cit,3,55);
//	cout << "num2 capacity: " << num2.capacity() << endl;
//	display(num2);

	cit = num2.begin();
	num2.erase(cit);
//	display(num2);
//	num2.clear();
	num2.erase(cit,cit+5);
//	display(num2);
//	cout << "num2 capacity: " << num2.capacity() << endl;
//	display(num2);
//	cout << num2.size() << endl;
//	cout << "num2 capacity: " << num2.capacity() << endl;
	list <int> li(arr,arr+5);
	display(li);
	li.push_back(7);
	li.push_front(0);
	display(li);
	li.pop_back();
	display(li);


}
 
int main(){
	test0();
	return 0;
}
