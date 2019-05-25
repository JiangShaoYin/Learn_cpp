 /// @date    2018-06-26 22:51:29
  
  #include <math.h>
  #include <iostream>
  #include <functional>
  using std::cout;
  using std::endl;
 
  //具体类   基于对象编程
  class Figure {
  public:
 		using Display = std::function<void()>;
 		using Area = std::function<double()>;
 				//注册回调函数
 		void setDisplay(Display && cb)	{	_display = cb;	}
		void setArea(Area && cb)	{		_area = std::move(cb);	}
 			//执行回调函数
 void handleDisplay()	{
 		if(_display)
 					_display();
 						}
 							double handleArea()	{
 									if(_area)
 return _area();
 		else
 					return 0;
 						}
 						private:
 							Display _display;
 								Area _area;
 								};//end of Figure
 
 								class Circle{
 								public:
 									Circle(double radius)
 											: _radius(radius)	{		cout << "Circel(double)" << endl;	}
 												void show() const	{	cout << "Circle";}
 													double calArea()	{	return  Pi * _radius * _radius;	}
 													private:
 														double _radius;
 															static double Pi;
 															};//end of Circle
 
 															double Circle::Pi = 3.14159;
 
 															class Rectangle{
 															public:
 																Rectangle(double length, double width)
 																		: _length(length)
 																				, _width(width)	{	cout << "Rectangle(double,double)" << endl;	}	
 																					void display() const{	cout << "Rectangle";	}
 																						double area()	{	return _length * _width;	}
 																						private:
 																							double _length;
 																								double _width;
 																								};//end of Rectangle
 
 																								class Triangle{
 																								public:
 																									Triangle(double a, double b, double c)
 																											: _a(a), _b(b), _c(c)	{		cout << "Triangle()" << endl;	}
 																												void print()const	{	cout << "Triangle";	}
 																													double getArea()	{
 																															double p = (_a + _b + _c) / 2;
 																																	return sqrt(p * (p - _a) * (p - _b) * (p - _c));
 																																		}
 																																		private:
 																																			double _a;
 																																				double _b;
 																																					double _c;
 																																					};//end of Triangle
 
 																																					void display(Figure * fig){
 																																						fig->handleDisplay();
 																																							cout << "的面积:" << fig->handleArea() << endl;
 																																							}
 																																							 
 																																							 int main(void){
 																																								Figure fig;
 																																									Circle circle(5);
 																																										Rectangle rectangle(10, 11);
 																																											Triangle triangle(3, 4, 5);
 
 																																												fig.setDisplay(std::bind(&Circle::show, &circle));
 																																													fig.setArea(std::bind(&Circle::calArea, &circle));
 																																														display(&fig);
 
 																																															fig.setDisplay(std::bind(&Rectangle::display, &rectangle));
 																																																fig.setArea(std::bind(&Rectangle::area, &rectangle));
 																																																	display(&fig);
 
 																																																		fig.setDisplay(std::bind(&Triangle::print, &triangle));
 																																																			fig.setArea(std::bind(&Triangle::getArea, &triangle));
 																																																				display(&fig);
 																																																					return 0;
 																																																					}
 																																																					
