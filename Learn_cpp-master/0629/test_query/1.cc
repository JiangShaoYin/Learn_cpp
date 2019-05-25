 /// @date    2018-07-01 21:01:48
#include "query.h"
#include <iostream>
using std::cout;
using std::endl;
 
 
 
void test1() { 
#if 0
	TextQuery tq;
    QueryResult tmp = tq.query("the");
	QueryResult qr(tmp);
	qr.display();
#endif
	TextQuery tq;
	Query q("the");//创建了WordQuery对象，用QueryBase型shared_ptr指针对象
						
	//调q里面QueryBase指针_q, _q访问QueryBase对象的纯虚函
	//数rep(rep由其派生类WordQuery实现)
	cout << q.rep() << endl <<endl;
	QueryResult res= q.eval(tq);//通过实现层的eval函数(纯虚函数，具体实现由派生类WordQuery完成)
	res.display();	
} 
 
int main(){
	test1();
	return 0;
}
