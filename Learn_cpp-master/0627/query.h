
/// @file    text_query.cc
/// @author  jiang(tooo_cold@163.com)
/// @date    2018-06-20 22:48:57

#ifndef __TESTQUERY_H__
#define __TESTQUERY_H__

#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::map;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::ostream;
using line_no = vector<string>::size_type;

class QueryResult;
class TestQuery{
	public:
		TestQuery();
	//	void read_file(const string filename);
		TestQuery(const string filename);
	//	void query(const string &word);
		QueryResult query(const string&) const;
	//	
	private:
		void process(string & line);
//		vector<string> _lines;
//		map<string, set<int> > _words;
		shared_ptr< vector<string> > _lines;		//定义shared_ptr型文件指针_file，将文件输入到_file所指容器(按行保存)
		map<string, shared_ptr<set<line_no>> > _words;//保存单词和单词出现行号的集合
		map<string,int> _word_freq;
};

class QueryResult {
	public:
friend ostream& operator<<(ostream& os, const QueryResult &rhs);
		QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f, line_no cnt)
			:_find(s), _line_num(p), _lines(f), _word_freq(cnt) {}
	private:
		string _find;
		shared_ptr<set<line_no>> _line_num;	//lines保存一个word，出现的行号
		shared_ptr<vector<string>> _lines;
		line_no _word_freq;
};//end of QueryResult

#endif 
