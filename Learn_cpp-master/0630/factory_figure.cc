 /// @date    2018-06-30 16:10:41
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;

class Figure {
public:
virtual void display() = 0;
virtual double area() = 0;
virtual ~Figure() {}
};//end of Figure

class Circle:public Figure {
	public:
		Circle(double radius)
			:_radius(radius) {}
	void display() {cout << "Circle" << endl;}	
	double area() {return 3.14 * _radius * _radius;}
	private:
		double _radius;
};//end of Circle

class Rectangle:public Figure {
	public:
		Rectangle(int length, int width)
		:_length(length), _width(width) {}
	void display() {cout << "Rectangle" << endl;}	
	double area() {return _length * _width;}
	private:
		int _length;
		int _width;
};//end of Rectangle

class Factory {
	public:
	virtual	Figure * create() = 0;
	virtual ~Factory() {}
};//end of Factory 
 
class CircleFactory : public Factory {
	public:
		Figure * create() {
			return (Figure*)new Circle(5);
		}
};//end of CircleFactory

class RectangleFactory : public Factory {
	public:
		Figure *create() {
			return (Figure*)new Rectangle(3,4);
		}
};

void show(Figure* fig) {
	fig->display();
	cout << fig->area() << endl;
}

void test1() { 
	unique_ptr<Factory> cir_fac(new CircleFactory());//创建circleFactory,由Factory基类型指针,cir_fac托管
	unique_ptr<Figure> cir_fig(cir_fac->create());	 //创建Figure基类型的指针cir_fig,托管circle对象(基类型中的create()表现为多态,执行派生类的操作)
	show(cir_fig.get());//get拿到cir_fig托管的circle对象的原生裸指针
	unique_ptr<Factory> rec_fac(new RectangleFactory());//rec_fac是Factory型指针，可以调用矩形工厂vfptr表里的函数
	unique_ptr<Figure> rec_fig(rec_fac->create());
	show(rec_fig.get());
} 
 
int main(){
	test1();
	return 0;
}
