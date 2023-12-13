//============================================================================
// Name        : GameInventory.h
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class GameInventory {
private:
	string name;
	string brand;
	int year;
	double price;

public:
	//constructors
	GameInventory();
	GameInventory(string name, string brand, int year, double price);

	//getters
	string getName() const { return name; }
	string getBrand() const { return brand; }
	int getYear() const { return year; }
	double getPrice() const { return price; }

	//print the contents of a GameInventory object
	void displayGame();

	//check if two GameInventory objects are equal/describing the same game)
	bool isSimilar(const GameInventory& game);
};

//searches the GameInventory vector v for GameInentory object game, returns true of its found
bool searchInventory(vector<GameInventory>& v, GameInventory& game);

//prints the contents of the GameInventory vector v
void displayInventory(vector<GameInventory>& v);

//adds a new GameInventory object to vector v if an equivalent object isn't already present
bool addNewGame(vector<GameInventory>& v, GameInventory& game);
