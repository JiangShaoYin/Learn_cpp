 ///
 /// @file    log4cpp.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-11 20:44:55
#ifndef  _MYLOG_H__
#define  _MYLOG_H__
#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp; 
 
namesapce wd{

	class Mylog{
		public:
			static Mylog * getInstance();
			static void destroy();
		private:
			Mylog();
			~Mylog();
			Category & _root;
			static Mylog * _pInstance;
	};
}//end of wd







