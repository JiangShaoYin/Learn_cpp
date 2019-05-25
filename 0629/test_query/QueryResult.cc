 /// @date    2018-07-01 17:12:52
#include "QueryResult.h"
#include <iostream>
#include <iostream>
using std::cout;
using std::endl;

QueryResult::QueryResult(string str,
						shared_ptr<vector<string>> ptr_vec,
						shared_ptr<set<int> > ptr_set,
						int cnt) 
	:_sought(str),  _file(ptr_vec), _lines(ptr_set), _cnt(cnt) {}

void QueryResult::display() {
	cout << _sought << " occurs "  << _cnt << " times" << endl;
	for(auto & num :*_lines) {
		cout << "line " << num+1 << ":" << endl;
			cout << (*_file)[num] << endl;;
	}
	


}
