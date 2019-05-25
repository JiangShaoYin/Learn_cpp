 ///
 /// @file    extern.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-05 20:52:34
 
#include<stdio.h> 

#ifdef __cplusplus
extern "C"{
#endif
int add(int x,int y){
		return x+y;
	}
#ifdef __cplusplus
}
#endif
int add(int x,int y,int z){
	return x+y+z;
}

int main(){
	int a=3,b=4,c=5;
	printf("%d\n",add(a,b));
	printf("%d\n",add(a,b,c));

	return 0;
}
