//============================================================================
// Name        : GameInventory.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include "GameInventory.h"
using namespace std;



GameInventory::GameInventory() {
	this->name = "";
	this->brand = "";
	this->year = 0;
	this->price = 0;
}
GameInventory::GameInventory(string name, string brand, int year, double price) {
	this->name = name;
	this->brand = brand;
	this->year = year;
	this->price = price;
}



void GameInventory::displayGame() {
	cout << "Name: " << name << ", Brand: " << brand << ", Year: " << year << ", Price: " << price << endl;
}

bool GameInventory::isSimilar(const GameInventory& game) {
	if (name == game.getName() && brand == game.getBrand() && year == game.getYear() && price == game.getPrice()) {
		return true;
	}
	return false;
}

bool searchInventory(vector<GameInventory>& v, GameInventory& game) {

	for (GameInventory g : v) {
		if (g.isSimilar(game) == true) {
			return true;
		}
	}

	return false;

}

void displayInventory(vector<GameInventory>& v){

	for (GameInventory g : v) {
		g.displayGame();
	}

}

bool addNewGame(vector<GameInventory>& v, GameInventory& game) {

	try {
		bool found = searchInventory(v,game);

		if (found == false) {
			v.push_back(game);
			return true;
		}

		else {
			throw (found);
		}
	}

	catch (bool f) {
		return false;
	}

}
