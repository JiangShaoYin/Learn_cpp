 ///
 /// @file    computer.h
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-06 18:31:54
 
 
 
#ifndef _COMPUTER_H__
#define _COMPUTER_H__

class computer{
		char  _brand[20];
		float _price;
	public:
		void setbrand(const char * brand);
		void setprice(float price);
		void print();
//	private:
};
#endif
