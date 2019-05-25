 /// @date    2018-07-01 18:04:04
 
#include "TextQuery.h"
#include <memory>
#include <sstream>
#include <fstream>
using std::make_shared;
using std::ifstream;
using std::istringstream;


TextQuery::TextQuery(){
	_file = make_shared<vector<string> >(vector<string>());
	string line;
	size_t num= 0;
	ifstream ifs("china_daily.txt");
	while(getline(ifs, line)) {
		(*_file).push_back(line);
	istringstream iss(line);
	string word;
	while(iss >> word) {
		auto find = _word.find(word);
		if(find == _word.end()) {//在_word没有找到要插入的单词
			auto tmp = new set<int>();
			tmp->insert(num);
			shared_ptr<set<int>> sh_ptr_set(tmp);
				_word.insert(std::make_pair(word, sh_ptr_set));
		}
		else
			find->second->insert(num);//_word中有要插入的单词，将单词出现的行数加入set中
		auto find_freq = _freq.find(word);
		if(find_freq == _freq.end())
			_freq.insert(std::make_pair(word,1));
		else
			++_freq[word];
		}	//end of while(iss >> word) 
		++num;
	}		//end of while(getline())
}
QueryResult TextQuery::query(const string word)const {
	auto find = _word.find(word);
	auto find_cnt = _freq.find(word);
		auto tmp = new set<int>();
		shared_ptr<set<int> > sh_ptr_set(tmp);

	if(find != _word.end())
		return QueryResult(word, _file, find->second, find_cnt->second);	
	else
		return QueryResult(word, _file, sh_ptr_set, 0);	
	}

