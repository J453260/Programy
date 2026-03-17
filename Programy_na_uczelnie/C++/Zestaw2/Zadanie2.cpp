#include <iostream>
using namespace std;

class Shape {
protected:
  long int _x; 
  long int _y;
public:
  Shape(long x,long y):_x(x),_y(y){};
  long get_x() const {return _x;}
  long get_y() const {return _y;}
  virtual void draw() = 0;
  virtual ~Shape() {};
};

class Circle : public Shape {
public:
  Circle(long x,long y) : Shape(x,y) {}
  
  void draw() override {
    cout << "Drawing circle\n";
  }
};

class Square : public Shape {
public:
  Square(long x,long y) : Shape(x,y) {}

  void draw() override {
    cout << "Drawing square\n";
  }
};

int main()
{
    Shape* s1 = new Circle(10,20);
    Shape* s2 = new Square(5,5);

    s1->draw();
    s2->draw();
    return 0;
}