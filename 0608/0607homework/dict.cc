 ///
 /// @file    dict.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-10 16:01:19
 
#include <string> 
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::map;
using std::ofstream;

struct Word{
	string _word;
	int _cnt;
	bool operator<(const Word &word){
		if(_cnt!=word._cnt)
			return word._cnt<_cnt;
		else
			return _word<word._word; 
		};
	};
 
class dict{
	public:
		void read(const string &FILE){
			fstream in(FILE);
			while(in){
				string word;
				in >> word;
				bool newword=true;
				if(!isdigit(word[0])){
				for(auto &p:_wordlist){
					if(p._word==word){
						p._cnt++;
						newword=false;
						break;
					}
				}
				if(newword){
					Word addword;
					addword._word=word;
					addword._cnt=1;
					_wordlist.push_back(addword);
				}
				}
			//	cout << "read....." << endl;
			}
			cout << "read success!!!!" << endl;
			in.close();
		}
		void write(const string & FILE){

			ofstream out(FILE);
			sort(_wordlist.begin(),_wordlist.end());
			for(auto &p:_wordlist){
			//	cout << "writing..." << endl;
				out << p._word  << " " 
					<< p._cnt <<endl; 
			}
			out.close();
			cout << "write done @!!!!" << endl;
		}
	private:
		vector <Word> _wordlist;
};

int main(){
	dict bible;
	bible.read("The_Holy_Bible.txt");
	bible.write("dict.txt");
	return 0;
}
