
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

String::String(String &&rhs) {
	cout << "String(String && rhs)" << endl;
	_pstr = rhs._pstr;
	rhs._pstr = NULL;
}

String & String::operator=(String && rhs) {
	delete _pstr;
	_pstr = rhs._pstr;
	rhs._pstr = NULL;
	cout << "operator=(String && rhs)" << endl;
	return *this;
}

std::size_t String::size() const{
	return strlen(_pstr);
}
const char* String::c_str() const{
	return _pstr;
}
ostream &operator<<(ostream &os, const String &s){
	os << s._pstr;
	return os;
}
String::~String() {
	delete _pstr;
	cout << "~String()" << endl;
}
