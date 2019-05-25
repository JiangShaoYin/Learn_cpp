 ///
 /// @file    log4cpp.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-11 20:44:55
 
 
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
 
int main(){
	PatternLayout *layout1 = new PatternLayout();
		layout1->setConversionPattern("%d [%p] %m%n");
	FileAppender *fileAppender = new FileAppender("1","jiang.txt");
		fileAppender->setLayout(layout1);

	Category & root =Category::getRoot().getInstance("root");


	PatternLayout *layout2 = new PatternLayout();
		layout2->setConversionPattern("%d [%p] %m%n");
	RollingFileAppender *rollingfileAppender = new RollingFileAppender("2","rolling_jiang.txt",5*1024);
		rollingfileAppender->setLayout(layout2);

	root.addAppender(fileAppender);
	root.addAppender(rollingfileAppender);
	
	root.setPriority(Priority::DEBUG);
	for(int idx=0;idx<100;idx++){
		ostringstream oss;
		oss << "this is " << idx << "message!";
		root.error(oss.str());
	}
	Category::shutdown();
	return 0;


	return 0;
}
