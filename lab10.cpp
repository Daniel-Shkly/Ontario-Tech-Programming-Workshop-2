//============================================================================
// Name        : lab10.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   :
// Description : convert a decimal number into its binary form
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Conversion {
	private:
		char* char_number;

	public:
		//Constructor
		Conversion (const char *number) {
			//Get length of character array
			int l = sizeof(number)/sizeof(number[0]);

			//Initialize char_number as an array of size l+1
			char_number = new char[l+1];

			//Copy contents of number over into char_number
			for (int i = 0; i < l; i++) {
				char_number[i] = number[i];
			}
		}

		//Converts a number in decimal form to binary
		void decimalToBinary(int n) {
			//n=0 is the exit condition meaning you've made it through the
			//whole number and there is nothing left to calculate
			if (n != 0) {
				//In this order because the digits have to be
				//displayed in the reverse order they were
				//calculated in
				decimalToBinary(n/2);
				cout << n%2;
			}
		}

		//Converts char_number into an integer
		//and calls decimalToBinary
		void convert() {
			int decimal = stoi(char_number);

			decimalToBinary(decimal);
		}

		//Destructor
		~Conversion() {
			char_number = NULL;
			delete char_number;
		}
};

int main() {

	//Initialize character array
	char number[10];

	//Get user input
	cout << "Enter an integer to convert into binary: ";
	cin >> number;

	//Create Conversion using user input
	Conversion conversion = Conversion(number);

	//Display converted number
	cout << "Binary of " << number << " is: ";
	conversion.convert();

	return 0;
}
