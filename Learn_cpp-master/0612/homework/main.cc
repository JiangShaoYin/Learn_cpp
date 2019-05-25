 ///
 /// @file    main.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-12 22:51:20
 
#include "String.h" 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
 
void test(){
//	String str1();
	String str2("hello,world");
//	String str3(str2);
//	String str3=str2;
//	String str4;
//		str4 = str2;
	String str5;
		str5="haha";
//	str5 += str2;
//	str5.print();
//	str5 += "WD21018";
//	str5.print();
//	for(std::size_t i=0;str5[i]!='\0';++i){
//		cout << str5[i] << endl;
//	}
//	const String str6(str5);
//		for(std::size_t i=0;str6[i]!='\0';++i){
//		cout << str6[i] << endl;
//	}
//	cout << str5.size() << endl;	
//	cout << "c_str " << str5.c_str() << endl;
//	cout << "str5==str5: " << (str5==str5) << endl;
//	cout << "str5==str2: " << (str5==str2) << endl;
//	cout << "str5!=str5: " << (str5!=str5) << endl;
//	cout << "str5!=str2: " << (str5!=str2) << endl;
//	cout << "str5 < str5: " << (str5<str5) << endl;
//	cout << "str5 < str2: " << (str5<str2) << endl;
//	cout << "str5 > str5: " << (str5>str5) << endl;
/*	cout << "str5 > str2: " << (str5>str2) << endl;
	cout << "str5 >= str5: " << (str5>=str5) << endl;
	cout << "str5 >= str2: " << (str5>=str2) << endl;
	cout << "str5 <= str5: " << (str5<=str5) << endl;
	cout << "str5 <= str2: " << (str5<=str2) << endl;
	cin >> str6; 
	cout << str6 << endl;
	cout << "before cin:" << str5 << endl;
	String str6;
	cin >> str5;
	cout << "after cin:" << str5 << endl;
 *
 */
	cout << str2+str5 << endl;
	cout << str2+"aaaaaaaaaaaaa" << endl;
	cout << "aaaaaaaaaaaaa"+str2 << endl;

} 
 
int main(){
	test();
	return 0;
}
