#include "GameInventory.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//Set of existing games
	vector<GameInventory> games = {
		{"Need for Speed", "XBox", 2018, 45.0},
		{"Hitman 2", "Playstation", 2020, 75.5},
		{"Mario Brothers", "Nintendo", 2010, 30.0},
		{"Assassin's Creed", "Playstation", 2021, 70.5},
		{"Uncharted 4: A Thief's End", "Playstation", 2020, 85.0},
		{"Spiderman Miles Morales", "XBox", 2021, 65.5},
		{"Resident Evil", "XBox", 2018, 45.0},
	};

	//Displaying current Games in the Inventory
	cout << "Current Games in the Inventory" << endl;
	cout << "**********************************" << endl;
	displayInventory(games);

	//Adding a new game
	GameInventory game = GameInventory("Hitman 3", "Playstation", 2022, 95);
	cout << "\nAdding another game in the Inventory..." << endl;

	//Checks to see if this game already exists in the collection
	if (searchInventory(games, game))
	{
		cout << "\nFollowing Game already exists in the Inventory..." << endl;
		game.displayGame();
	}
	else
	{
		if (addNewGame(games, game))
		{
			cout << "\nFollowing Game added to the inventory successfully..." << endl;
			game.displayGame();
			cout <<endl;
		}
	}

	//Displaying current Games in the Inventory
	cout << "Current Games in the Inventory" << endl;
	cout << "**********************************" << endl;
	displayInventory(games);

	//Adding another new game which already exists in the inventory
	game = GameInventory("Need for Speed", "XBox", 2018, 45.0);
	cout << "\nAdding another game in the Inventory..." << endl;

	//Checks to see if this game already exists in the collection
	if (searchInventory(games, game))
	{
		cout << "\nFollowing Game already exists in the Inventory..." << endl;
		game.displayGame();
		cout << endl;
	}
	else
	{
		if (addNewGame(games, game))
		{
			cout << "\nFollowing Game added to the inventory successfully..." << endl;
			game.displayGame();
			cout << endl;
		}
	}

	//Displaying current Games in the Inventory
	cout << "Current Games in the Inventory" << endl;
	cout << "**********************************" << endl;
	displayInventory(games);

	return 0;
}
