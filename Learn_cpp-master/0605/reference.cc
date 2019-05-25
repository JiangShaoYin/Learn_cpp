#include<iostream>
using std::cout;
using std::endl;
int arr[]={1,2,3,4,5};
int *p=new int(10);
int *p2=new int [5] ();

int & func(int i){
	return arr[i];
}

int main(){
	cout<<"*p ="<<*p<<endl;
	delete p;
	for(int idx=0;idx<5;idx++)
	{
		p2[idx]=idx;
		cout<<"p2[idx]="<<p2[idx]<<endl;
	}
	delete [] p2;

	func(0)=555;
	cout<<"func(0)="<<func(0)<<endl;


	return 0;
}
