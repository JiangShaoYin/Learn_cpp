 
 /// @file    deleter.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 12:27:49
#include <stdio.h> 
#include <memory> 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::string;

struct FdCloser {
	void operator()(FILE *p) {
		fclose(p);
	}
};

void test() {
	unique_ptr<FILE, FdCloser> u_p(fopen("1.txt", "w+"),FdCloser());
	string str("hello world");
	fwrite(str.c_str(), 1, str.size(),u_p.get());
} 

void test1() {
	shared_ptr<FILE> s_p(fopen("1.txt", "w+"), FdCloser());
	string str("naa");
	fwrite(str.c_str(), 1, str.size(), s_p.get());
}

int main(){
	test1();
	return 0;
}
