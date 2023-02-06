//============================================================================
// Name        : CSCI1061U_lab03.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Bit Stuffing, program that takes a user sequence and see which
//				 lines in the provided file contain a matching sequence
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bits {
private:
	string sequence;
	string packet;

public:
	string getSequence() {
		return sequence;
	}

	string getPacket() {
		return packet;
	}

	void setSequence(string s) {
		sequence = s;
	}

	void setPacket(string s) {
		packet = s;
	}

	void toString() {
		cout << packet << ": " << sequence << endl;
	}

	bool isEmpty() {
		if (sequence == "" || packet == "") {
			return true;
		}
		else {
			return false;
		}
	}

	Bits() {
		this->sequence = "";
		this->packet = "";
	}

	Bits(string sequence, string packet) {
		this->sequence = sequence;
		this->packet = packet;
	}
};

//function to increase the size of an array by 1, will fail if it's increased
//by anything more than 1
Bits* resize(Bits* arr, int* size) {
	//create new array
	Bits* new_arr = new Bits[*size + 1];

	//copy old into new
	for (int i = 0; i < *size; i++) {
		new_arr[i] = arr[i];
	}

	//delete old
	delete[] arr;

	return new_arr;
}

//checks if a word is present in a longer word and returns a Bits object if true
Bits getBitsObject(string word, string user_sequence) {

	//start at 5 becuase each line in the file starts with "P0#: "
	for (int i = 5; i + user_sequence.length() < word.length(); i++) {

		int count = 0;

		for (int y = i; y - i < user_sequence.length(); y++) {
			if (word[y] == user_sequence[y-i]) {
				count++;
			}
		}

		if (count == user_sequence.length()) {

			return Bits(user_sequence, word);
		}
	}

	return Bits();
}

//function to print the contents of a Bits array
void display(Bits *arr, int size) {
	cout << "\n*****Bit Sequences Found*****" << endl;

	for (int i = 0; i < size; i++) {
		cout << arr[i].getPacket() << endl;
	}

	cout << "\nTotal occurrences: " << size-1 << endl;
}

void fileProcessing(string user_sequence, string file) {
	ifstream bits;
	string packet;
	int* size = new int;
	*size = 1;
	Bits* arr = new Bits[*size];
	Bits bit = Bits();

	//open file
	bits.open(file);

	//main loop, loops through the whole file line by line
	while (getline(bits,packet)) {

		bit = getBitsObject(packet, user_sequence);

		if (bit.getPacket() != "") {

			arr = resize(arr, size);
			*size = *size + 1;
			arr[*size-1] = bit;

		}

	}

	//close file
	bits.close();

	//display results
	display(arr, *size);

	//delete pointers
	delete[] arr;
	delete size;
}

int main() {

	char cont = 'y';
	string sequence;

	while (cont == 'y') {
		cout << "Enter a bit sequence: ";
		cin >> sequence;

		fileProcessing(sequence, "bits.txt");

		cout << "Continue? (y/n): ";
		cin >> cont;
	}


	return 0;
}
