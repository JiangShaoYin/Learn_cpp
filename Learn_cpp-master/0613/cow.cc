 ///
 /// @file    cow.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-13 22:20:24
#include <stdio.h> 
#include <string.h> 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
 
class String{
	class CharProxy{
		public:
			CharProxy(size_t idx,String & self)
			:_idx(idx)
			,_self(self){}
		CharProxy & operator=(const char & ch);
//friend ostream & operator<<(ostream & os,const CharProxy & rhs);
friend ostream & operator<<(ostream & os,const CharProxy & rhs);
//		operator char(){return _self._p[_idx];}
		private:
			size_t _idx;
			String & _self;
	};
//friend ostream & operator<<(ostream & os,const CharProxy & rhs);
friend ostream & operator<<(ostream & os, const CharProxy & rhs);
	public:
		String()
		:_p(new char[5]){
			_p+=4;
			initRefcnt();
		//	cout << "String()" << endl;
		}
		String(const char *str)
		:_p(new char[5+strlen(str)]){
			_p+=4;
			initRefcnt();
			strcpy(_p,str);
		//	cout << "String(const char *str)" << endl;
		}
		String(const String &rhs)
		:_p(rhs._p){
			increaseRefcnt();
		//	cout << "String(const String &)" << endl;
		}
		String & operator=(const String & rhs){
			if(this!=&rhs){
				release();
				_p=rhs._p;
				increaseRefcnt();
			}
			return *this;
		}
		int refcnt(){	return	*(int*)(_p-4);	}
		size_t size()  {	return strlen(_p);}
		char * c_str(){	return _p;}
		
	CharProxy & operator[](size_t idx){
			return CharProxy(idx,*this);
		}

friend	ostream & operator<<(ostream &os,String & rhs);
	~String(){
		release();
	//	cout << "~String" << endl;
	}

	private:
		void initRefcnt(){	*((int*)(_p-4))=1;}
		void decreaseRefcnt(){	--*((int*)(_p-4));}
		void increaseRefcnt(){	++*((int*)(_p-4));}
		void release(){	
				decreaseRefcnt();
			if(refcnt()==0){
				delete [](_p-4);
		//	cout << "heap data deleted" << endl;
			}
		}
	private:
		char * _p;
};//end of class

String::CharProxy & String::CharProxy::operator=(const char &ch){//CharProxy中的成员函数
	if(_idx < _self.size()){
		if(_self.refcnt()>1){
			char * tmp = new char[4+_self.size()+1];
			tmp+=4;
			strcpy(tmp,_self._p);
			_self.decreaseRefcnt();
			_self._p=tmp;
			_self.initRefcnt();
		}
		_self._p[_idx]=ch;
	}
	return *this;
}

ostream & operator<<(ostream &os,String & rhs){
				os << rhs._p;
				return os;
		}
//ostream & operator<<(ostream & os,const String::CharProxy & rhs){
ostream & operator<<(ostream & os,const String::CharProxy & rhs){
	os << rhs._self._p[rhs._idx];
	return os;
}


int main(){
	String str1("aaaaaaaa");
	String str2("hello world");
/*	cout << str2 << str1 << endl;
 *	
	str3[0]='X';
	printf("str2=%p\n",str2.c_str());
	printf("str3=%p\n",str3.c_str());
	cout << "str2= " << str2 << endl;
	cout << "str3= " << str3 << endl;
*/
	String str3(str2);
	printf("str2=%p\n",str2.c_str());
	printf("str3=%p\n",str2.c_str());
	cout << str2.refcnt() << endl;
	cout << endl;
	
	cout << str3[0] << endl;
	printf("str2=%p\n",str2.c_str());
	printf("str3=%p\n",str3.c_str());
	return 0;
}
