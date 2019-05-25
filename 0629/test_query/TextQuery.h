 /// @date    2018-07-01 17:57:52
 
#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__
#include "QueryResult.h"
#include <map>
using std::map;

class TextQuery {
	public:
		TextQuery();
		QueryResult query(const string) const;
	private:
		map<string, shared_ptr<set<int> > > _word;
		shared_ptr<vector<string> > _file;
		map<string,int> _freq;
};//end of TextQuery
#endif
