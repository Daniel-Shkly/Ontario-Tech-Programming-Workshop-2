//============================================================================
// Name        : CSCI1061U_lab09.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


//function that finds the largest element in an array 'arr' of size 'size'
template<typename T>
T findMax(T arr[], int size) {
	T max_val = arr[0];

	for (int i = 0; i < size; i++) {

		if (arr[i] > max_val) {
			max_val = arr[i];
		}

	}
	return max_val;
}


//template specialization to handle strings and find the longest string
//instead of the string starting with the latest alphabetic letter
template<>
string findMax(string arr[], int size) {
	string longest = arr[0];

	for (int i = 0; i < size; i++) {

		if (arr[i].length() > longest.length()) {
			longest = arr[i];
		}

	}
	return longest;
}


int main() {

	//declarations
	double decimals[] = {-3.4, 58.1, -76.4, 34.4};
	int integers[] = {2, 3, 81, 1, 9, 22};
	string characters[] = {"Ontario", "Tech", "University", "Oshawa", "Canada"};

	//get array sizes
	int s_decimals = sizeof(decimals) / sizeof(decimals[0]);
	int s_integers = sizeof(integers) / sizeof(integers[0]);
	int s_characters = sizeof(characters) / sizeof(characters[0]);

	//print out the decimal array and the largest number in it
	cout << "Array of decimals...\n" ;
	cout <<	for_each(begin(decimals), end(decimals), [](double something){cout << something << ", ";})
			<< "\n" << "The largest decimal: " << findMax(decimals, s_decimals) << "\n" << endl;

	//print out the integer array and the largest number in it
	cout << "Array of integers...\n";
	cout << for_each(begin(integers), end(integers), [](int something){cout << something << ", ";})
			<< "\n" << "The largest integer: "  << findMax(integers, s_integers) << "\n" << endl;

	//print out the string array and the longest string in it
	cout << "Array of Characters...\n" ;
	cout <<	for_each(begin(characters), end(characters), [](string something){cout << something << ", ";})
			<< "\n" << "The largest character sequence: " << findMax<string>(characters, s_characters) << "\n" << endl;

	return 0;
}
