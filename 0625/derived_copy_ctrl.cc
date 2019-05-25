 
 /// @file    derived_copy_ctrl.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-25 23:06:30
 
 
#include <string.h> 
#include <iostream>
  using std::cin;	   
  using std::endl;
	using std::cout;
     class Base {
public:
      Base(){}
	 Base(const char *ptr)
	     :_ptr(new char[strlen(ptr) + 1]) {
	          cout << "Base(const char * ptr)" << endl;
	          strcpy(_ptr, ptr);
	         }
 Base(const Base & rhs)
	     :_ptr(new char[strlen(rhs._ptr) + 1]) {
	          cout << "Base(const Base & rhs)" << endl;
	          strcpy(_ptr, rhs._ptr);
	          }
              ~Base() {
		                 if(_ptr) { 
				                  delete _ptr;
				                    cout << "~Base()" << endl;
					               }
			                 }
	          private:
			            char * _ptr;
		 };//end of Base

       class Derived
	   :public{
			        public:
					       private:
	   };
