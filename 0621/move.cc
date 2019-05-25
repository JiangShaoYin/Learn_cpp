 
 /// @file    move.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-21 15:57:13
 
#include <string.h> 
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ostream;

class String{
	public:
		String();
		String(const char *pstr);
		String(const String & rhs);
		String(String && rhs);	
		String & operator=(const String & rhs);
		String & operator=(String && rhs);
		const char* c_str() const;
		~String();
friend ostream & operator<<(ostream & os, const String & rhs);
	private:
		char* _pstr;
};
String::String()
	:_pstr(new char[1]()) {}

String::String(const char *pstr)
	:_pstr(new char[strlen(pstr) + 1])
{
	cout << "String::String(const char *pstr)" << endl;
	strcpy(_pstr, pstr);
}

String::String(const String &rhs) {//拷贝构造函数
	cout << "String::String(const String &rhs)" << endl;
	_pstr = new char[strlen(rhs._pstr) + 1];
	strcpy(_pstr, rhs._pstr);
}

String::String(String && rhs) {
	cout << "(String &&rhs)" << endl;
	_pstr = rhs._pstr;
	rhs._pstr =	NULL;
}

String & String::operator=(const String & rhs) {//赋值构造函数
	cout << "operator=(const String & rhs)" << endl; 
	delete [] _pstr;
	_pstr = new char[strlen(rhs._pstr) + 1];
	strcpy(_pstr, rhs._pstr);
	return *this;
}

String & String::operator=(String && rhs) {
	cout << "operator=(String && rhs)" << endl;
	delete [] _pstr;
	_pstr = rhs._pstr;
	rhs._pstr =	NULL;
	return *this;
}
const char* String::c_str() const {
	return _pstr;
}
String::~String() {
	cout << "~String()" <<endl;
	if(_pstr) {
	delete [] _pstr;
	cout << "_pstr != NULL, ~String" << endl;
	}
}
ostream & operator<<(ostream & os, const String & rhs) {
	os << rhs._pstr;
	return os;
}

void test() {
//	vector <String> vec;
//	vec.push_back("wangdao");
//	vec.push_back("wngdao");
//	String s1;
	String s1("hello world");
	String s2("shenzhen");
	cout << s1 << endl;
	cout << endl;

	printf("s1 :%p",s1.c_str());
	s2 = std::move(s1);
	printf("s2 :%p",s2.c_str());
	cout << s1 << endl;
//	String s3 = String("hel world");
//	cout << s2 << endl;
//	s2 = String("nihao");
}
 
int main(){
	test();
	return 0;
}
