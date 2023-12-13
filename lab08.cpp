//============================================================================
// Name        : lab08.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Practice with STL array
//============================================================================

#include <iostream>
#include <array>

using namespace std;

//linear search through array to see if 'num' parameter already exists in 'arr'
bool duplicateSearch(array<int,10> arr, int num) {

	for (int i = 0; i < 10; i++) {
		if (arr[i] == num) {
			return true;
		}
	}

	return false;
}

int main() {

	//initialize array with all values being 0
	const int SIZE = 10;
	array<int, SIZE> arr{};
	int num;

	cout << "Enter 10 integers between 10 and 100:" << endl;

	//main loop
	for (int i = 0; i < 10; i++) {

		//prompts user to enter number
		cout << "Enter a number: ";
		cin >> num;

		//if number is valid...
		if (num >= 10 && num <= 100) {
			//if number is a duplicate, do not add it to the array
			if (duplicateSearch(arr,num) == true) {
				cout << "Duplicate number.\n" << endl;
			}

			//add number to array at position i
			else {arr[i] = num;}
		}

		//if number is not valid, then tell the user
		//and decrement i so that loop continues
		//until 10 valid numbers are entered
		else {
			cout << "Invalid number. Please enter a number between 10 and 100.\n" << endl;
			i--;
		}
	}

	//Display non-duplicates
	cout << "The non-duplicate values are: " << endl;
	for (int i = 0; i < 10; i++) {
		//positions where a duplicate was entered are still 0 as initialized
		//so only prints positions which contain unique numbers
		if (arr[i] != 0) {
			cout << arr[i] << " ";
		}
	}

	return 0;
}
