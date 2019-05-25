#include "Mylog.h"

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::ostringstream;
using namespace log4cpp; 
using namespace wd;

Mylog * _pInstance = NULL;
Mylog * Mylog::getInstance(){
	if(!_pInstance){
		_pInstance = new Mylog();
		return _pInstance;
	}
}
void Mylog::destory(){
	if(!_pInstance){
		delete _pInstance;
		_pInstance = NULL;
		return NULL;
	}
}


Mylog::Mylog()
	:_root(Category.getRoot().getInstance("root"))
	{
	PatternLayout *layout1 = new PatternLayout();
		layout1->setConversionPattern("%d [%p] %m%n");
	PatternLayout *layout2 = new PatternLayout();
		layout2->setConversionPattern("%d [%p] %m%n");
	OstreamAppender * ostreamAppender = new OstreamAppender("ostringstream",&cout);
	FileAppender * fileAppender = new FileAppender("fileAppender","wangdao.txt");
	ostreamAppender->setLayout(layout1);
	fileAppender->setLayout(layout2);

	_root.addAppender(ostreamAppender);
	_root.addAppender(fileAppender);
	_root.setPriority(Priority::DEBUG);
	}	

Mylog::~Mylog(){
	Category::shutdown();
}






#endif
