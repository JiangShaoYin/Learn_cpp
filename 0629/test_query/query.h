 /// @date    2018-07-01 16:10:38
#ifndef __QUERY_H__
#define __QUERY_H__
#include "TextQuery.h"

class QueryBase {
	friend class Query;
	public:
		virtual ~QueryBase() {}
	private:
		virtual QueryResult eval(const TextQuery &) = 0;
		virtual string rep() = 0;
};//end of QueryBase

class WordQuery : public QueryBase{
	friend class Query;
	private:
		WordQuery(string word) :_sought(word) {}
		virtual QueryResult eval(const TextQuery &tq) {	return tq.query(_sought);}
		string rep(){return _sought;}
	private:
		string _sought;
};// end of WordQuery

class Query {
	public:
		Query(string word) :_q(new WordQuery(word)){}
		QueryResult eval(const TextQuery &tq) {	return _q->eval(tq);}
		string rep() {return _q->rep();}
	private:
		Query(shared_ptr<QueryBase> q)	//用QueryBase指针q构造Query对象
			:_q(q) {}			
		shared_ptr<QueryBase> _q;		//保存实现层的指针，由实现层完成功能，通过接口层返回
};//end of Query
#endif
