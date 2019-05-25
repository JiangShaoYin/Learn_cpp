 /// @file    heap.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-18 21:45:00 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <class T,typename compare = std::less<T> >
class HeapSort{
	public:
		HeapSort(T *arr,size_t size);
		void max_heap(T *arr,size_t start,size_t size);
		void heap_sort(T *arr,size_t size);
		void print() const { for(size_t i=0;i<_size;++i)cout << _arr[i] << " ";	cout << endl;}
	private:
		T *_arr;
		size_t _size;
};
 
template <class T>
inline
void swap(T &t1,T &t2) {
	T tmp = t1;
	  t1 = t2;
	  t2 = tmp;
}

template <class T,typename compare >
HeapSort<T,compare>::HeapSort(T *arr,size_t size)
					:_arr(arr)
					,_size(size)
{
	heap_sort(_arr,_size);
	cout << "HeapSort(T *arr,size_t size) " << endl;
}

template <class T,typename compare >
void HeapSort<T,compare>::max_heap(T *arr,size_t start,size_t size) {
	cout << "start=" << start << " " << "size=" << size << endl;
  size_t dad=start;
  size_t son=dad * 2 + 1;
  while(son < size) {
	  if(son+1 < size&&arr[son+1] > arr[son]) {
		swap(arr[son],arr[son+1]);
	  }

	  if(arr[son] > arr[dad]) {
			swap(arr[dad],arr[son]);
			dad = son;
			son = dad * 2 + 1;
	  }
	  else
		  break;
  }
}
template <class T,typename compare >
void HeapSort<T,compare>::heap_sort(T *arr,size_t size) {
			for(int i = size/2 -1;i >= 0;--i) {
				max_heap(arr,i,size);
			}

			swap(arr[0],arr[size-1]);
			for(int i=size-1;i>0;--i) {
				max_heap(arr,0,i);
				swap(arr[0],arr[i-1]);
			}
}
void test() {
	int num[5]={2,1,3,5,4};
	HeapSort<int> arr1(num,sizeof(num)/sizeof(num[0]));	
	arr1.print();
}
void test1() {
	double num[5]={4.4,2.2,3.3,1.1,5.5};
	HeapSort<double> arr1(num,sizeof(num)/sizeof(num[0]));	
	arr1.print();
}
void test3() {
	double num[5]={4.4,2.2,3.3,1.1,5.5};
	HeapSort<double,std::greater<double> > arr1(num,sizeof(num)/sizeof(num[0]));	
	arr1.print();
}

int main(){
	test();
	test1();
	test3();
	return 0;
}
