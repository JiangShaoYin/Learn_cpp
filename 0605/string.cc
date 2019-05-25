 ///
 /// @file    string.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 09:34:02
#include <stdio.h> 
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test(){
	string s1="hello,";
	string s2="world";
	string s3=s1+s2;
	string s4=s1+"nima";
	string s5=s1+"nima";
	cout<<s3<<endl;
	cout<<s4<<endl;
	cout<<s5<<endl;
	for(auto& ch :s3)
		cout<<ch<<endl;
	string s6=s3.substr(0,5);
	string s7=s3.substr(5,6);
	cout<<s6<<endl;
	cout<<s7<<endl;
	cout<<(s1==s2)<<endl;
	const char *sptr=s1.c_str();
	const char *sptr2=s1.data();
	for(int i=0;i<6;i++){
		printf("%c\n",sptr[i]);
		printf("%c\n",sptr2[i]);

	}
}
int main(){
	test();
	return 0;
}
