 /// @file    homework.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-12 21:52:59
 
#ifndef _STRING_H__
#define _STRING_H__

#include <iostream>
using std::cout;
using std::endl; 

class String {
	public:
		String();
		String(const char *);
		String(const String&);
		~String();
		String &operator=(const String &);//返回类型为String
		String &operator=(const char *);
		String &operator+=(const String &);
		String &operator+=(const char *);
		char &operator[](std::size_t index);
		const char &operator[](std::size_t index) const;
		std::size_t size() const;
		const char* c_str() const;
		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);
		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);

		friend std::ostream &operator<<(std::ostream &os, const String &s);
		friend std::istream &operator>>(std::istream &is, String &s);
		void print(){
			cout << _pstr << endl;
		}
	private:																																			
    	char * _pstr;
	};

      String operator+(const String &, const String &);
      String operator+(const String &, const char *);
      String operator+(const char *, const String &);

#endif 
