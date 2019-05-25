 
 /// @file    test.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-20 16:56:04
 
#include <algorithm> 
#include <vector>
#include <iostream>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::iterator;

void test(){
	vector<int> num{1,2,3,4,5,6};
	vector<int>::iterator it = std::lower_bound(num.begin(), num.end(),4);
	cout << *it << endl;

} 
 
int main(){
test();

	return 0;
}
