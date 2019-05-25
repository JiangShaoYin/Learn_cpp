 ///
 /// @file    student.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-08 20:58:18
#include <string.h> 
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

class Student{
	public:
		Student(int id,const char* name)
			:_id(id)
			,_name(new char[strlen(name)+1]())
		{
			cout << "Student(int id,const char* name)" << endl;
			strcpy(_name,name);
		}

	void * operator new (size_t size){
		cout << "void * operator new (int size)" << endl;
		void * ret =malloc(size);
		return ret;
	}
	
	void operator delete(void *ret){
		free(ret);
		cout << " operator delete  " << endl;
	}
	void destory(){
		delete this;
		cout << "void destory" << endl;
	}
	void print(){
		cout << _id << _name << endl;
	}
	private:
		~Student(){
			delete _name;
			cout << "~Computer" << endl; 
		}
		int _id;
		char *_name;
};
 
 
int main(){
//	Student stu(123,"Alice");
	Student *pstu = new Student(101,"xiongda");
	pstu->print();
	pstu->destory();
//	delete ipstu;
	return 0;
}
