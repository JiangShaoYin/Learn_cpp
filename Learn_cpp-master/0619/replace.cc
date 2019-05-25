 
 /// @file    replace.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-19 20:03:45
 
#include <algorithm> 
#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::replace_if;
using std::vector;
using std::less;
using std::ostream_iterator;
using std::bind2nd;

void test() {
	vector <int> num{1,2,3,4,5,6};
	std::less<int> lt;//lt(1st,2nd)
	replace_if(num.begin(), num.end(),bind2nd(lt,4), 10);
	std::copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}
 
 
int main(){
	test();
	return 0;
}
