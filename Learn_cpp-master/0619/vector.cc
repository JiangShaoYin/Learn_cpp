 
 /// @file    vector.cc
 /// @author  jiang(tooo_cold@163.com)
 /// @date    2018-06-20 10:56:34
 
#include <memory> 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::allocator;
using std::ostream;
 
template <class T>
class Vector{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start;}
		iterator end() { return _finish;}
		Vector();
		~Vector();
		void push_back(const T & t);
		int size() const{	return _finish-_start;}
		int capacity() const {	return _end-_start;}
	private:
		void reallocate();
		static allocator<T> _alloc;
		T* _start;
		T* _finish;
		T* _end;
};

template <class T>
allocator<T> Vector<T>::_alloc;
template <class T>
Vector<T>::Vector()
			:_start(0)
			,_finish(0)
			,_end(0){}
template <class T>
Vector<T>::~Vector() {
	while(_finish != _start) {
		_alloc.destroy(--_finish);
	}
	_alloc.deallocate(_start, capacity());
	cout << "~Vector()" << endl;
}
template <class T>
void Vector<T>::push_back(const T & t) {
	if(size()==capacity())
		reallocate();
	_alloc.construct(_finish++,t);
}

template <class T>
void Vector<T>::reallocate() {
	int oldsize = capacity();
	int newsize = capacity() ? 2 * oldsize : 1;

	T* tmp = _alloc.allocate(newsize);
	std::uninitialized_copy(_start, _finish, tmp);

	while(_finish !=_start)
		_alloc.destroy(--_finish);
	_start = tmp;
	_finish = _start + oldsize;
	_end = _start + newsize;
}

template <class Container>
void display(Container &t) {
	cout << "t.size()=" << t.size()
		 << " t.capacity()=" << t.capacity()
		 << endl;
}

class Point{
	public:
		Point(int x, int y)
			:_x(x)
			,_y(y){}
		~Point() {cout << "~Point()" << endl;}
	friend ostream & operator<<(ostream & os, const Point & rhs);
	private:
		int _x;
		int _y;
};
ostream & operator<<(ostream & os, const Point & rhs) {
	os << "(" << rhs._x
	   << "," << rhs._y
	   << ")" << endl;
	return os;
}

void test() {
	Vector<Point> points;
	points.push_back(Point(1,2));
	display(points);
	points.push_back(Point(3,4));
#if 0
	display(points);
	Vector<Point>::iterator it = points.begin();
	while(it != points.end()) {
		cout << *it << " " << endl;
		++it;
	}
# endif
}

int main(){
	test();
	return 0;
}
