 /// @date    2018-06-28 15:02:14
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <iostream>
#include <fstream>
#include <stringstream>
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::map;
using std::string;
using std::shared_ptr;
using std::ifstream;

using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery {
	public:
		using line_no = vector<string>::size_type;
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr< vector<string> > _file;		//定义shared_ptr型文件指针_file，将文件输入到_file所指容器(按行保存)
		map<string, shared_ptr<set<line_no>> > _word;//保存单词和单词出现行号的集合
};//end of TextQuery

class QueryResult {
	public:
		QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
			:_sought(s), _lines(p), _file(f) {}
	private:
		string _sought;
		shared_ptr<set<line_no>> _lines;	//lines保存一个word，出现的行号
		shared_ptr<vector<string>> _file;
};//end of QueryResult


TextQuery::TextQuery(ifstream &ifs)
	_file(new vector<string>) {
		string text;						//保存文件每行字符串，到text中
		while(getline(ifs, text)) {
			file->push_back(text);
			int num = file->size() -1;		//save the current line num with the format of array
			istringstream line(test);
			string word;
			while (line >> word ) {
				auto &lines = _word[word];//type of lines is 'shared_ptr'
				if(!lines)
					lines.reset(new set<line_no>)//lines托管set对象
				lines->insert(num);
			}
		}
	}

QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);//nodata指向行号的集合
	auto loc = _word.find(_sought);
	if (loc == _word.end())
		return QueryResult(_sought, nodata, _file);//编译器如何知道是哪个_file
	else
		return QueryResult(_sought, loc->second, _file);
}

ostream &print(ostream & os, const QueryResult &qr) {
	os << qr._sought << "occurs" << qr._lines->size() << endl;
	for(auto num : *qr._lines) {
			os << "(line " << num+1 << ")" 
			   << *(qr._file->begin() + num) << endl;
	}
	return os;
}
















 
void test1() { 
 
} 
 
int main(){
	test1();
	return 0;
}
