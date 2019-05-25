 ///
 /// @file    io1.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-08 23:10:37
#include <limits>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;


void printcin(){
	cout << "cin.goodbit=" <<cin.good() << endl;
	cout << "cin.badbit=" <<cin.bad() << endl;
	cout << "cin.failbit=" <<cin.fail() << endl;
	cout << "cin.eofbit=" <<cin.eof() << endl << endl;
} 
void test(){
/*	printcin();
	int num;
	while(cin>>num){
		cout << "num=" << num << endl;
	}
	printcin();

	cin.clear();
	printcin();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	string str;
	cin>>str;
	cout << "str=" << str << endl;
*/
	string line;
	while(getline(cin,line)){
		printcin();
	}
	cout << line << endl;
}

void stream_status(){
	int num;
	while(cin>>num,!cin.eof()){
		if(cin.bad()==1)
				return;
		else if(cin.fail()){
			cout << "input an integer" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		cout << "num = " << num << endl;

	}
}

int main(){
//	test();
	stream_status();
	return 0;
}
