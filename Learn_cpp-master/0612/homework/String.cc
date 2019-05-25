
#include "String.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::istream; 
using std::ostream; 
using std::vector;

String::String()
	:_pstr(new char[1])
	{
		cout << "String()" << endl;
	}
String::String(const char *str)
	:_pstr(new char[strlen(str)+1])
	{
		cout << "String(const char *str)" << endl;
		strcpy(_pstr,str);
		cout << _pstr << endl;
	}
String::String(const String&rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]){
	cout << "String::String(const String&rhs)" << endl;
	strcpy(_pstr,rhs._pstr);
}
String & String::operator=(const String &rhs){
	cout << "String & String::operator=(const String &rhs)" << endl;
if(_pstr)
	delete _pstr;
	_pstr=new char[strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
	return *this;
}
String & String::operator=(const char *str){
	cout << "String & String::operator=(const char *str)" << endl;
if(_pstr)
	delete _pstr;
	_pstr=new char[strlen(str)+1];
	strcpy(_pstr,str);
	return *this;
}
String &String::operator+=(const String &rhs){
	String tmp(*this);
if(_pstr)
	delete _pstr;
	_pstr = new char[strlen(tmp._pstr)+strlen(rhs._pstr)+1];
	strcpy(_pstr,tmp._pstr);
	strcat(_pstr,rhs._pstr);
	return *this;
}
String & String::operator+=(const char *str){
	String tmp(*this);
if(_pstr)
	delete _pstr;
	_pstr = new char[strlen(tmp._pstr)+strlen(str)+1];
	strcpy(_pstr,tmp._pstr);
	strcat(_pstr,str);
	return *this;
}
char & String::operator[](std::size_t idx){
	static char nullchar='\0';
	if(idx < strlen(_pstr))
		return _pstr[idx];
	else
		return nullchar;
}
const char & String::operator[](std::size_t idx) const{
//	cout << "const operator[]() const" << endl;
	static char nullchar='\0';
	if(idx < strlen(_pstr))
		return _pstr[idx];
	else
		return nullchar;
}
std::size_t String::size() const{
	return strlen(_pstr);
}
const char* String::c_str() const{
	return _pstr;
}
bool operator==(const String &lhs, const String &rhs){
	return strcmp(lhs._pstr,rhs._pstr)==0;
}
bool operator!=(const String &lhs, const String &rhs){
	return strcmp(lhs._pstr,rhs._pstr)==0?false:true;
}
bool operator<(const String &lhs, const String &rhs){
	return strcmp(lhs._pstr,rhs._pstr)<0;
}
bool operator>(const String &lhs, const String &rhs){
	return strcmp(lhs._pstr,rhs._pstr)>0;
}
bool operator>=(const String &lhs, const String &rhs){
	return strcmp(lhs._pstr,rhs._pstr)>=0;
}
bool operator<=(const String &lhs, const String &rhs){
	return strcmp(lhs._pstr,rhs._pstr)<=0;
}
ostream &operator<<(ostream &os, const String &s){
	os << s._pstr;
	return os;
}
istream &operator>>(istream &is, String &s){
	vector <char> tmp;
	char ch;
//	cout << "before getchar()" << endl;
	while(ch=getchar(),ch!='\n'){
		tmp.push_back(ch);
	}
//	cout << "after getchar()" << endl;
	if(s._pstr)
		delete s._pstr;
	s._pstr=new char[tmp.size()+1];
	int idx=0;
	for(auto & num:tmp)
		s._pstr[idx++]=num;
	s._pstr[idx]='\0';
	return is;
}

String operator+(const String &lhs, const String &rhs){
	String tmp;
	tmp+=rhs;
	tmp+=lhs;
	return tmp;
}
String operator+(const String &lhs, const char *str){
	String tmp;
	tmp+=lhs;
	tmp+=str;
	return tmp;
}
String operator+(const char *str, const String &rhs){
	String tmp;
	tmp+=str;
	tmp+=rhs;
	return tmp;
}
String::~String(){
	delete _pstr;
	cout << "~String()" << endl;
