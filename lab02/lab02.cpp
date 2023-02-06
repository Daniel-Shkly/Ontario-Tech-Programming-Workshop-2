//============================================================================
// Name        : CSCI1061U_lab02.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 2, takes a .txt file and finds all the words in it and
//               how many times each word appears
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class WordCounter {
	private:
		string word;
		int count;

	public:
		void setWord(string word) {
			this->word = word;
		}

		void incrementWordCount() {
			count += 1;
		}

		string getWord() {
			return word;
		}

		int getCount() {
			return count;
		}

		WordCounter(string word) {
			this->word = word;
			count = 1;
		}
};

//as the name suggests, this function takes a string and if the first
//character is a capital letter, it makes it lower case.
//not general, but works well enough in this case
string makeFirstLetterLower(string word) {

	if (int(word[0]) > 64 && int(word[0]) < 91) {
		word[0] = char(int(word[0]) + 32);
	}

	return word;
}


//redundant version of below function included for assignment requirements
//version below does the same thing but returns index instead of just true/false
bool isFound(vector<WordCounter> &v, string word) {

	for (WordCounter wc : v) {
		if (wc.getWord() == word) {
			wc.incrementWordCount();
			return true;
		}
	}

	return false;

}

//function that finds if the word is is in the vector and returns its index
//if it is present else returns -1
int isFoundWithIndex(vector<WordCounter> &v, string word) {

	int i = 0;

	word = makeFirstLetterLower(word);

	for (WordCounter wc : v) {
		if (wc.getWord() == word) {
			return i;
		}
		i++;
	}

	return -1;

}

//function to print out the unique words and their counts
void printReport(vector<WordCounter> &v) {
	for (WordCounter wc : v) {
		cout << wc.getWord() << ": " << wc.getCount() << endl;
	}
}

//opens the file 'data.txt' and finds all the unique words in the file and the number times they appear
//stores those values is the vectors 'words' and 'count' respectively
void processFile() {

	//initialize variables
	ifstream data;
	char c;
	vector<WordCounter> words = {};
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

			word = makeFirstLetterLower(word);

			//check if the word constructed so far is present in the vector containing all unique words
			int found = isFoundWithIndex(words, word);

			//if it's not found, then add it to the vector
			if (found == -1) {
				words.push_back(WordCounter(word));
			}

			//increment count if word is found in the vector
			else {
				words[found].incrementWordCount();
			}

			//empty the word string so a new word can be constructed in it
			word = "";

		}

	}

	//close file
	data.close();

	//print out the words and counts
	printReport(words);
}


int main() {

	processFile();

	return 0;
}
