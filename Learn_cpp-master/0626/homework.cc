 /// @date    2018-06-27 23:06:28
#include <functional> 
#include <iostream>
using std::cout;
using std::endl;
using std::function;

class Figure {
public:
	using Dispaly = function<void()>;
	using Area = function<double()>;
	//注册回调函数
	void setDispaly(Dispaly && cd) {_display = cd;}
	void setArea(Area && cd) { _area = cd;}//把传递过来的cal_area函数，赋值给函数指针_area；
//处理完后，area指针指向类的计算面积函数。
	void handle_dispaly() {				   //执行回调函数
		if(_display)
			_display();
	}
	double handle_area() {
		if(_area)
			return _area();
		else
			return 0;
	}
private:
	Dispaly _display;
	Area _area;
};//end of Figure
 
class Circle {
	public:
		Circle(double radius)
			:_radius(radius) {cout << "Circle(double radius)" << endl;}
		void show() const {	cout << "Circle";}
		double cal_area() { return  PI * _radius * _radius; }
	private:
		double _radius;
		static double PI;
};//end of Circle

double Circle::PI = 3.14159;

class Rectangle {
	public:
		Rectangle(double length, double width) 
			:_length(length),
			_width(width) { cout << "Rectangle(double length, double width)" << endl;}
		void show() const {cout << "Rectangle";}
		double cal_area() {return _length * _width;}
	private:
		double _length;
		double _width;
};
void display(Figure *fig) {
	fig->handle_dispaly();
	cout << fig->handle_area() << endl;
}

void test1() { 
	Figure fig;
	Circle circle(3);
	Rectangle rectangle(4,5);
	fig.setDispaly(std::bind(&Circle::show, &circle));
	fig.setArea(std::bind(&Circle::cal_area, &circle));
	display(&fig);
cout << "........................................" << endl;	
	fig.setDispaly(std::bind(&Rectangle::show, &rectangle));
	fig.setArea(std::bind(&Rectangle::cal_area, &rectangle));
	display(&fig);
} 
 
int main(){
	test1();
	return 0;
}
