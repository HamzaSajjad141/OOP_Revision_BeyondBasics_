#include<iostream>
using namespace std;

class Myclass //class
{
public: // access specifier which could be public,private and public
	int num;	// Attribute
	string name;
	int Age;
	Myclass() // Constructor
	{
		cout << "I am constructor " << endl;
	}
	Myclass(int x, string y, int z) //parametrized constructor//
	{
		num = x;
		name = y;
		Age = z;
	}
	void mymethod(); // methods
	int mymethod2(int x);

	~Myclass()  // destructor 
	{
		cout << "I am destructor of Myclass" << endl;
	}


};


// encapsulation //
class myclass2 {
private:
	int length;
	int width;
public:
	void getterfunc(int x, int y) // getter method //
	{
		length = x;
		width = y;
	}

	int setterfunc() // setter method//
	{
		return length * width;
	}
};

// Single inheritance // 
class A {
protected:
	int a;
public:
	void setA() {
		cout << "Enter the value of A =>";
		cin >> a;
	}
	void displayA()
	{
		cout << "The Value of A is : " << a << endl;
	}

};

class B : public A {
	int b, p;
public:
	void setB()
	{
		setA();
		cout << "Enter the value of B =>";
		cin >> b;
	}

	void displayB()
	{
		displayA();
		cout << "The value of B is : " << b << endl;
	}

	void prod()
	{
		p = a * b;

		cout << "The product of " << a << " and " << b << "=" << p << endl;
	}

};



// Multiple Inheritance // 

class c1
{
protected:
	int x;
public:
	void setx()
	{
		cout << "Enter the value of x : ";
		cin >> x;
	}

	void displayx()
	{
		cout << "The value of x is :" <<x<<endl;

	}

};

class c2
{
protected:
	int y;
public:
	void sety()
	{
		cout << "Enter the value of y : ";
		cin >> y;
	}

	void displayY()
	{
		cout << "The value of y is :" << y << endl;

	}

};

class d1 : public c1, public c2 
{
protected:
	int p, z;
public:
	void setz()
	{
		setx();
		sety();
		cout << "Enter the value of z : ";
		cin >> z;
	}

	void displayZ()
	{
		displayx();
		displayY();
		cout << "The value of z is :" << z << endl;

	}

	void productZ()
	{
		p = x * y * z;
		cout << "The product of " << x << "*" << y << "*" << z << "=" << p << endl;

	}


};


// Multilevel Inheritance //
class c {
protected:
	int w;
public:
	void setw()
	{
		cout << "Enter the Value of w : ";
		cin >> w;
	}

	void displayw()
	{
		cout << "The Value of w is : " << w << endl;
	}

};

class b : public c
{
protected:
	int x;
public:
	void setx()
	{
		setw();
		cout << "Enter the Value of x : ";
		cin >> x;
	}

	void displayx()
	{
		displayw();
		cout << "The Value of x is : " << x << endl;
	}


};

class a : public b
{
protected:
	int p;
public:
	

	void Prodp()
	{
		setx();
		displayx();
		p = w * x;
		cout << "The Value of product is : " << p << endl;
	}

};


// polymorphism means many forms type 1 : function overloading // 

class hamza
{
public:
	void func(int x)
	{
		cout << "The value of x is : " << x << endl;
	}

	void func(double y)
	{
		cout << "The value of y is : " << y << endl;
	}
};


// polymorphism means many forms type 1 : operator overloading for Binary Operators // 

class Complex {
private:
	int real, imag; //Attributes
public:
	Complex() // Constructor
	{
		real = 0;
		imag = 0;
	}

	Complex(int r, int i) // Parametrized Constructor 
	{
		real = r;
		imag = i;
	}

	void printP()  // Method
	{
		cout << real << "+" << imag << "i" << endl;
	}

	void printS()  // Method
	{
		cout << real << "-" << imag << "i" << endl;
	}

	Complex operator + (Complex c) // operator overloading function 
	{
		Complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;
	}

	Complex operator - (Complex c) // operator overloading function 
	{
		Complex temp;
		temp.real = real - c.real;
		temp.imag = imag - c.imag;
		return temp;
	}


};


// polymorphism means many forms type 1 : operator overloading for Unary Operators // 

class Weight {
private :
	int kg;
public:
	Weight() // Constructor
	{
		kg = 0;
	}
	Weight(int x) // Param Constructor 
	{
		kg = x;
	}

	void printWeight() // Method
	{
		cout << "Weight in kg : " << kg << endl;
	}


	void operator ++()  // operator overloading pre increment operator unary
	{
		++kg;
	}


	void operator ++(int)  // operator overloading post increment operator unary
	{
		kg++;
	}




	void operator --()  // operator overloading pre decrement operator unary
	{
		--kg;
	}


	void operator --(int)  // operator overloading post decrement operator unary
	{
		kg--;
	}


/*Weight operator ++ () // this will do the work if you want to do like this x = ++y logic //
	{
		weight = temp;
		temp.kg = ++kg;
		return temp;
	}*/
};



// polymorphism means many forms type 1 : operator overloading for Stream Extraction Operators // 

class Test 
{
private:
	int x;
public:
	Test()
	{
		x = 0;
	}
	
	// friend function decleration 
	friend istream& operator >> (istream& input, Test& obj);
	friend ostream& operator << (ostream& output, Test& obj);


};

// friend function outside the class 
istream& operator >> (istream& input, Test& obj)
{
	input >> obj.x;
	return input;

}


ostream& operator << (ostream& output, Test& obj)
{
	output << obj.x;
	return output;
}



// way of declare method outside the class by scope resolution 
void Myclass::mymethod()
{

	cout << "I am Hamza from mymethod method in class" << endl;
}


int Myclass::mymethod2(int x)
{

	cout << "I am Hamza from mymethod2 method in class" << endl;
	return x;
}


int main() 
{
	//Object 1//
	Myclass obj1; // obj
	obj1.num = 22; 
	cout << obj1.num << endl;
	obj1.mymethod(); // calling the methods
	cout << "mymethod2 returns => " << obj1.mymethod2(21) << endl;



	//Object 2//
	Myclass obj2(11, "Hamza", 22);//parametrized constructor calling //
	cout << "Obj2 values -=-=>>";
	cout << obj2.num << " " << obj2.name << " " << obj2.Age << endl;



	// class no 2 // 
	myclass2 obj3;//instance of class //
	obj3.getterfunc(2, 3);
	cout << "setterFunc returns => " << obj3.setterfunc() << endl;



	// for single inheritance class //
	cout << endl;
	cout << "------>SINGLE INHERITANCE<-------" << endl;
	B obj5;
	obj5.setB();
	obj5.displayB();
	obj5.prod();


	// for multiple inheritance // 
	cout << endl;
	cout << "------>MULTIPLE INHERITANCE<-------" << endl;
	d1 obj9;
	obj9.setz();
	obj9.displayZ();
	obj9.productZ();


	// for multilevel inheritance // 
	cout << endl;
	cout << "------>MULTILEVEL INHERITANCE<-------" << endl;
	a obj11;
	obj11.Prodp();



	// polymorphism means many forms type 1 : function overloading // 
	cout << endl;
	cout << "------>FUNCTION OVERLOADING<-------" << endl;
	hamza Q;
	Q.func(2);
	Q.func(3.36666);
	cout << "Hamza Sajjad" << endl;


	// polymorphism means many forms type 1 : operator overloading for Binary Operators // 
	cout << endl;
	cout << "------>OPERATOR OVERLOADING (Binary Operators)<-------" << endl;
	Complex c1(6, 5);
	Complex c2(2, 4);
	Complex c3;
	c3 = c1 + c2; // operator overloading on binary operator 
	c3.printP();
	Complex c4;
	c4 = c1 - c2;
	c4.printS();

	
	// polymorphism means many forms type 1 : operator overloading for Unary Operators // 
	cout << endl;
	cout << "------>OPERATOR OVERLOADING (Unary Operators)<-------" << endl;
	Weight d;
	cout << "Before pre increment " << endl;
	d.printWeight();
	cout << "After Pre increment " << endl;
	++d;
	d.printWeight();
	cout << "After Post Increment " << endl;
	d++;
	d.printWeight();
	cout << "After Pre decrement " << endl;
	--d;
	d.printWeight();
	cout << "After Post decrement " << endl;
	d--;
	d.printWeight();


	// polymorphism means many forms type 1 : operator overloading for Stream Extraction Operators // 
	cout << endl;
	cout << "------>OPERATOR OVERLOADING (Stream/Extraction Operators)<-------" << endl;
	Test obj0;
	cout << "Stream : ";
	cin >> obj0;
	cout << "Extraction : " << obj0 << endl;;




	return 0;
}

