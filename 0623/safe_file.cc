 
 /// @file    safe_file.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-24 13:08:06
 
#include <stdio.h> 
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class SafeFile{
	public:
		SafeFile(FILE * fp)
			:_fp(fp)
			{
					
			}
		void write (const string  msg) {
			fwrite(msg.c_str(), sizeof(char), msg.size(), _fp);
		}
		~SafeFile() {
			if(_fp) {
				fclose(_fp);
			cout << "~SafeFile()" << endl;
			}
			}
	private:
		FILE *_fp;
};
 
int main(){
	SafeFile test(fopen("haha","w"));
	test.write("hello world");
	return 0;
}
