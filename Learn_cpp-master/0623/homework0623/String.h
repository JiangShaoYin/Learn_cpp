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

		String(String && rhs);
		String & operator=(String && rhs);

		std::size_t size() const;
		const char* c_str() const;

		friend std::ostream &operator<<(std::ostream &os, const String &s);
	private:																																			
    	char * _pstr;
	};
#endif 
