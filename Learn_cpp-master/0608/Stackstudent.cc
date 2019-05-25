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

	void print(){
		cout << _id << _name << endl;
	}
	private:
	void * operator new (size_t size);
	void operator delete(void *ret);
		int _id;
		char *_name;
};
 
 
int main(){
	Student stu1(101,"xiongda");
//	Student *pstu = new Student(102,"lele");
	stu1.print();
//	pstu->print();
//	delete pstu;
	return 0;
}
