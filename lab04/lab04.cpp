//============================================================================
// Name        : CSCI1060U_lab04.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Program that implements a complex number class and overloaded
//               operators to work with complex numbers
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
	double real;
	double complex;

public:
	//getters
	double getReal() {
		return real;
	}
	double getComplex() {
		return complex;
	}

	//setters
	void setReal(double real) {
		this->real = real;
	}
	void setComplex(double complex) {
		this->complex = complex;
	}

	//constructors
	Complex() {
		real = 0;
		complex = 0;
	}
	Complex(double real, double complex) {
		this->real = real;
		this->complex = complex;
	}

	//operators
	Complex operator+ (Complex& operand) {
		Complex c;
		c.setReal(this->real + operand.getReal());
		c.setComplex(this->complex + operand.getComplex());

		return c;
	}
	Complex operator- (Complex& operand) {
		Complex c;
		c.setReal(this->real - operand.getReal());
		c.setComplex(this->complex - operand.getComplex());

		return c;

	}
	Complex operator* (Complex& operand) {
		Complex c;
		c.setReal((this->real * operand.getReal()) - (this->complex * operand.getComplex()));
		c.setComplex((this->complex * operand.getReal()) + (this->real * operand.getComplex()));

		return c;

	}
	bool operator== (Complex& operand) {
		bool equal;
		if (this->real == operand.getReal() && this->complex == operand.getComplex()) {
			equal = true;
		}
		else {
			equal = false;
		}

		return equal;
	}
	friend ostream& operator<< (ostream& output, Complex& complex);

};


ostream& operator<< (ostream& output, Complex& complex) {
	output << "(" << complex.real << " , " << complex.complex << ")";

	return output;
}

//extract real part of a complex number from a string in the form "(a,b)" where
//'a' is the real part and 'b' is the complex part
double extractReal(string str) {
	string real = "";
	for (int i = 1; str[i] != ',';i++) {
		real += str[i];
	}

	return stod(real);
}

//extract complex part of a complex number from a string in the form "(a,b)"
//where 'a' is the real part and 'b' is the complex part
double extractComplex(string str) {
	int len = str.length();
	string complex = "";
	for (int i = len-2; str[i] != ','; i--) {
		complex = str[i] + complex;
	}

	return stod(complex);

}

//takes a boolean and returns a string for easier reading when displayed
string printBool(bool e) {
	if (e == true) {
		return " == ";
	}
	return " != ";
}

int main() {

	Complex first = Complex();
	string sFirst;
	Complex second = Complex();
	string sSecond;

	cout << "Enter the first complex number in the form (a,b): ";
	cin >> sFirst;

	cout << "Enter the second complex number in the form (a,b): ";
	cin >> sSecond;

	first.setReal(extractReal(sFirst));
	first.setComplex(extractComplex(sFirst));

	second.setReal(extractReal(sSecond));
	second.setComplex(extractComplex(sSecond));

	Complex add = first + second;
	Complex subtract = first - second;
	Complex multiply = first * second;
	bool equal = first==second;


	cout << "\n*********************************************"
			"\n            Results of Calculations "
			"\n*********************************************" << endl;

	cout << first << " + " << second << " = " << add << endl;
	cout << first << " - " << second << " = " <<  subtract << endl;
	cout << first << " * " << second << " = " <<  multiply << endl;
	cout << first << printBool(equal) << second << endl;

	cout << "*********************************************" << endl;

	return 0;
}
