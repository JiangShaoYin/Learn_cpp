 
 /// @file    remove.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-19 19:27:00
#include <algorithm> 
#include <vector> 
#include <iostream>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::remove; 
using std::ostream_iterator;

void test() {
	vector <int> num{1,2,66,4,7,8,66};
//	auto it=remove(num.begin(), num.end(), 66);
//	num.erase(it,num.end());
	num.erase(remove(num.begin(), num.end(), 66),num.end() );
	for(auto & number:num){
		cout << number << " ";
	}
	cout << endl;
	std::copy(num.begin(), num.end(), ostream_iterator<int>(cout," "));
}
 
int main(){
	test();
	return 0;
}
