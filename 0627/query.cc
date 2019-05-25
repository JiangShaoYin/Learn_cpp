 
 /// @file    query.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-21 12:08:33
 
#include "query.h" 
#include <string.h>
#include <fstream>
#include <sstream>
using std::ifstream;


//TestQuery::TestQuery() {_lines.reserve(120);	} 
TestQuery::TestQuery(const string filename) {
	ifstream ifs(filename);
	string line,word;
	int line_num=0;
	while(getline(ifs, line)) {
		_lines = std::make_shared<vector<string>>( vector<string>() );
//		_lines->reserve(120);
		_lines->push_back(line);	
		process(line);
		std::istringstream iss(line);
			cout << "before read" << endl;
		while(iss >> word) {
			++_word_freq[word];//word已存在，则value++。word不存在，插入word，默认值value=0，也执行value++
			_words[word]->insert(line_num);	
		}
		++line_num;
	}
	cout << "read done!" << endl;
} 

QueryResult TestQuery::query(const string &word) const {
	static shared_ptr< set<line_no> > nothing(new set<line_no>);
	auto exist = _words.find(word);//查找到的是行号集合set<line_no>的指针
	auto word_cnt = _word_freq.find(word);
	if(exist!=_words.end())
		return QueryResult(word, exist->second, _lines, word_cnt->second);
	else
		return QueryResult(word, nothing, _lines, word_cnt->second);
}


ostream& operator<<(ostream& os, const QueryResult &rhs) {
		os << rhs._find << " occurs " << rhs._word_freq << " "
		   << "times "  << endl;
			for(auto num: *(rhs._line_num) ){
				cout << "  (line " << num+1 << ") "  << (*rhs._lines)[num] << endl;
			}
			return os;
}


void TestQuery::process(string & line) {
		for(auto & ch:line) {
			if(!isalpha(ch)) {
				ch = ' ';
			}
		}
}
int main(int args, char * argv[]) {
	TestQuery tq("china_daily.txt");
	QueryResult qr = tq.query(argv[1]);	
	cout << qr;
	return 0;
}
