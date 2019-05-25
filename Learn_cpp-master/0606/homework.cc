 ///
 /// @file    homework.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 22:58:34
#include <string.h> 
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;
class String{
	public:
		String()
			:_pstr(NULL)
		{
			cout<<"String()"<<endl;
		}
		String(const char *pstr)
			:_pstr(new char[strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout<<"String(const char *pstr)"<<endl;
		}
		String(const String & rhs)
			:_pstr(new char[strlen(rhs._pstr)+1]())
		{
			strcpy(_pstr,rhs._pstr);
			cout<<"copy constructor!!!"<<endl;
		}




		void print(){
			if(_pstr)
				cout<<_pstr<<endl;
			else
				cout<<"_pstr == NULL"<<endl;
		}

		~String(){
			delete [] _pstr;
			_pstr=NULL;
			cout<<"destructor done!!!"<<endl;
		}
	private:
		char *_pstr;
};
 
int main(){
	String str1;
	str1.print();
cout<<endl;
	
	String str2 = "hello,world";
	str2.print();
cout<<endl;

	String str3("wangdao");
	str3.print();
cout<<endl;

	String str4=str3;
	str4.print();
	return 0;
}
