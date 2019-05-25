 
 /// @file    for_each.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-19 17:35:31
 
#include <algorithm> 
#include <vector>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector; 
using std::string;

void func(int &idx) {
	++idx;
	cout << idx << " "; 
}
void test() {
	vector<int> num{1,2,3,4,5,6};
	for_each(num.begin(),num.end(),func);
	cout << endl;
	for(auto & number:num){
		cout << number << " ";
	}
	cout << endl;
	for_each(num.begin(),num.end(),[](int numbers){
				cout << numbers << " ";
			});
	cout << endl;
	auto it = std::find(num.begin(),num.end(),4);
	cout << *it << endl;	
	string s1("to accept sth which is not the best,but is most available");
	string s2("most");
	auto s3 = std::search(s1.begin(),s1.end(),s2.begin(),s2.end());
	for(;s3!=s1.end();s3++){
	//	cout << "*" << endl;
		cout << *s3 << endl;
	}
}

int main(){
	test();
	return 0;
}
