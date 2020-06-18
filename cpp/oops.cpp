//aim of OOP is to bind together the dataand the functions that operate on them so that no other part of the code can access this data except that function.
//Encapsulation also leads to data abstraction or hiding
//abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
//polymorphism as the ability of a message to be displayed in more than one form.
//Operator Overloading: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
//Function Overloading: Function overloading is using a single function name to perform different types of tasks.
//Inheritance: The capability of a class to derive properties and characteristics from another class is called Inheritance.
//Function overriding on the other hand occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
//The capability of a class to derive properties and characteristics from another class is called Inheritance.

#include <iostream>

using namespace std;

//A class is like a blueprint for an object.
class person
{
private:
	// data hidden from outside world 
	char name[20];
	int id;
public:
	void getdetails();

	int sum(int a, int b)
	{
		return(a+b);
	}
	int sum(int a, int b, int c)
	{
		return(a + b + c);
	}
};

//operator overloading
class Complex {
private:
	int real, img;
public:
	Complex(int r = 0, int i = 0) { real = r; img = i; }
	//this is automatically called when '+' is used with b/w two complex objects.
	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.img = img + obj.img;
		return res;
	}
	void print() { cout << real << "+i" << img; }
};


//function overriding
class base
{
public:
	virtual void print()	{
		cout << "print base class" << endl;
	}
	void show()	{
		cout << "show base class" << endl;
	}
};

class derived :public base
{
public:
	void print() //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly 
	{
		cout << "print derived class" << endl;
	}

	void show()
	{
		cout << "show derived class" << endl;
	}
};


//Inheritance
//Base class 
class Parent
{
private:
	int id_a;
public:
	int id_p;
};

// Sub class inheriting from Base Class(Parent) 
class Child : public Parent
{
public:
	int id_c;
};

int main()
{
	person p1;    //An Object is an instance of a Class.

	//polymorphism : function overloading
	int sum1 = p1.sum(10, 20);
	int sum2 = p1.sum(10, 20,30);
	cout << "sum1 " << sum1<<"sum2 "<<sum2;

	//polymorphism : operator overloading
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+"
	c3.print();

	//function overriding
	base* bptr;
	derived d;
	bptr = &d;
	//virtual function, binded at runtime (Runtime polymorphism)
	//Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing kind of derived class object.
	bptr->print();
	// Non-virtual function, binded at compile time 
	bptr->show();

	//Inheritance
	Child obj1;
	obj1.id_c = 7;
	obj1.id_p = 91;
	//obj1.id_a = 4;
	cout << "Child id is " << obj1.id_c << endl;
	cout << "Parent id is " << obj1.id_p << endl;


	return 0;

}