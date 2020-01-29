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
	ss << "number1 " << 123; // 如果不加空格，则两个部分会写到一起。
	cout << ss.str() << endl;
	int num;
	string str;
	// ss >> str >> num; // 将ss中空格的第一个字段写成string，第2个字段写成int
	ss >> str; // 将ss中空格的第1个字段写成string，
	ss >> num; // 第2个字段写成int

	cout << str << endl
		 << num << endl;
}

void readconf(){
	ifstream ifs("sever.conf");
	string line;
	string key,value;
	while(getline(ifs, line)){
	// ifs:
	// ip  192.168.30.128
	// port 8888
		stringstream iss(line);
		iss >> key >> value; // 将iss内的字符，写入key和value字段内，如果只写1个的话
		cout << key << " " << value << endl;
	}
	ifs.close();
}

int main(){
	test();
	readconf();
	return 0;
}
