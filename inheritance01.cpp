// inheritance01.cpp
// inheritance example 
#include <iostream> 
#include <string> 

using namespace std; 


class Shape
{
	private:
		string shapeType;
	public: 
		Shape()
			{cout << "No argument constructor called" << endl;}
		Shape(string s): shapeType(s) 
			{cout << "One argument constructor" << endl;}
		Shape(const Shape& rhs)
			{shapeType = rhs.shapeType;}
		~Shape()
			{cout << "Destructor" << endl;}
		Shape& operator=(const Shape& rhs){
			if (this != &rhs) {
				shapeType = rhs.shapeType;
				}
			return *this;
			}
		void print_shape_type(){
			cout << shapeType << endl;
		}
};

class Circle : public Shape
{
	private:
		float radius;
	public:
		Circle()
			{cout << "No argument constructor called" << endl;}
		Circle(string s, double r): Shape(s),radius(r)
			{cout << "One argument constructor" << endl;}
		~Circle()
			{cout << "Destructor" << endl;}
		Circle(const Circle& rhs)
			{radius = rhs.radius;}
		Circle& operator=(const Circle& rhs){
			if (this != &rhs) {
				Shape::operator=(rhs);
				radius = rhs.radius;
			}
			return *this;
		}	
};

int main()
{
	cout << "start the program" << endl; 
	Shape shape1;
	Shape shape2("circle");
	Shape shape3; 
	shape3 = shape2; 
	shape3.print_shape_type();
	
	Circle c1("Some Shape", 3.5);
	cout << endl << "Instantiate object c2" << endl;
	Circle c2("Some other shape", 10.2);  
	cout << endl << "Assign c1=c2" << endl;
	c1 = c2;
	cout << endl << "Instantiate object c3 (copy constructor)" << endl;
	Circle c3 = c1; 
	cout << endl << "End of program" << endl;
	
	return 0;
}

