 ///
 /// @file    io3.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-10 20:48:28
#include <string>
#include <sstream> 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::ifstream;
void test(){
	stringstream ss;
	ss << "number1=: " << 123;
	cout << ss.str() << endl;
	int num;
	string str;
	ss >> str >> num;
	cout << str << endl
		 << num << endl;
}

void readconf(){
	ifstream ifs("sever.conf");
	string line;
	string key,value;
	while(getline(ifs,line)){
		stringstream iss(line);
		iss >> key >> value;
		cout << key << " "
			 << value << endl;
	}
	ifs.close();
}

int main(){
	test();
	readconf();
	return 0;
}
