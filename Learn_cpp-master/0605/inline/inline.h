 ///
 /// @file    inline.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-05 16:26:36
 ///
 

#ifndef __INLINE_H__   //为了防止一个头文件在一个模块(.c或.cc文件)之中include多次
#define __INLINE_H__

inline 
int add(int x, int y)
{
	return x + y;
}

#endif 
