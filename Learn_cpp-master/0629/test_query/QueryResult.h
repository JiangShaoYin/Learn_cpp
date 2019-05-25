 /// @date    2018-07-01 17:22:46

#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__
#include <memory>
#include <string>
#include <vector>
#include <set>
using std::shared_ptr;
using std::string;
using std::vector;
using std::set;

class QueryResult {
	public:
		QueryResult(string,
					shared_ptr<vector<string>>,
					shared_ptr<set<int> >,
					int);
		void display();
	private:
		string _sought;
		shared_ptr<vector<string> > _file;
		shared_ptr<set<int> > _lines;	//保存string出现的行号集合
		int _cnt;
};//end of QueryResult
#endif
