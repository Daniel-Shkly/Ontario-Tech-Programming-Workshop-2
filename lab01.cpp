//============================================================================
// Name        : CSCI1061U_lab01.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 1, takes a .txt file and finds all the words in it and
//               how many times each word appears
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//as the name suggests, this function takes a string and if the first character
//is a capital letter, it makes it lower case.
//not general, but works well enough in this case
string makeFirstLetterLower(string word) {

	if (int(word[0]) > 64 && int(word[0]) < 91) {
		word[0] = char(int(word[0]) + 32);
	}

	return word;
}


//function required by the lab, written to fulfill the requirements
//better/more fitting version found below
bool isFound(vector<string> v, string word) {

	for (string str : v) {
		if (str == word) {
			return true;
		}
	}

	return false;

}

//function that finds if the word is is in the vector and returns its index
//if it is present else returns -1
int isFoundWithIndex(vector<string> v, string word) {

	int i = 0;

	word = makeFirstLetterLower(word);

	for (string str : v) {
		if (str == word) {
			return i;
		}
		i++;
	}

	return -1;

}

//prints each word as well as how many times the word appears in the file
void printReport(vector<string> words, vector<int> count) {

	int i = 0;
	for (string str : words) {
		cout << str << ": " << count[i] << endl;
		i++;
	}
}

//opens the file 'data.txt' and finds all the unique words in the file and the number times they appear
//stores those values is the vectors 'words' and 'count' respectively
void processFile() {

	//initialize variables
	ifstream data;
	char c;
	vector<string> words = {};
	vector<int> count = {};
	string word = "";

	//open file
	data.open("data.txt");

	//main loop, loops through the whole file character by character and without skipping the spaces
	while (data >> noskipws >> c) {

		//if the character is not a space or line break, add it to the word
		if (c != ' ' && int(c) != 13 && int(c) != 10) {
			word += c;
		}

		//upon encountering a space or line break
		else if (c == ' ' || int(c) != 13 || int(c) != 10) {

			//check if the word constructed so far is present in the vector containing all unique words
			int found = isFoundWithIndex(words, word);

			//if it's not found, then add it to the vector
			if (found == -1) {
				words.push_back(makeFirstLetterLower(word));
				count.push_back(1);
			}

			//if it is found, increase the count of its occurrences by 1
			else {
				count[found] += 1;
			}

			//empty the word string so a new word can be constructed in it
			word = "";

		}

	}

	//close file
	data.close();

	//print out the words and counts
	printReport(words,count);
}

int main() {

	processFile();

	return 0;
}
