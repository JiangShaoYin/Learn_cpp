 ///
 /// @file    io2.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-08 23:56:43
 
#include <fstream> 
#include <iostream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string; 

void test(){
	ifstream ifs("io1.cc");
	string line;
	while(getline(ifs,line)){
		cout << line << endl;
	}
	ifs.close();
}

int main(){
	test();

	return 0;
}
