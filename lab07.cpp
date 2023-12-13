//============================================================================
// Name        : CSCI1061U_lab07.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Cd {
private:
	const char * performers;
	const char * label;
	int selections;
	double playtime;

public:
	Cd() {
		performers = new char[8];
		label = new char[8];
		selections = 0;
		playtime = 0.0;
	}

	Cd (const char * performers, const char * label, int selections, double playtime) {
		this->performers = new char[strlen(performers)+1];
		this->performers = performers;

		this-> label = label;
		this->selections = selections;
		this->playtime = playtime;
	}

	virtual void Report() {
		cout << "Performer(s): " << this->performers << "\n"
				"Label: " << this->label << "\n"
				"Number of Selections: " << this->selections << "\n"
				"Play time: " << this->playtime << endl;
	}

	virtual ~Cd() {}

};

class Classic : public Cd {
private:
	const char * primaryWork;

public:
	Classic() {
		primaryWork = new char[8];
		primaryWork = "Unknown";
	}

	Classic (const char * primaryWork, const char * performers, const char * label, int selections, double playtime)
	: Cd (performers, label, selections, playtime) {

		this->primaryWork = new char[strlen(primaryWork)+1];
		this->primaryWork = primaryWork;
	}

	virtual void Report() {
		cout << "Primary work: " << this->primaryWork << endl;
		Cd::Report();

	}

	~Classic() {}
};

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);

	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	// Create a parent pointer and make it point to Cd object
	Cd* ptr = new Cd;
	*ptr = c1;

	cout << "\nUsing object directly:\n";
	cout << "***************************" << endl;

    // Call Report() using Cd object
	c1.Report();

	// Call Report() using Classic object
	c2.Report();

	cout << "\nUsing type cd * pointer to objects:\n";
	cout << "***************************" << endl;

	// Call Report() using Cd type pointer created above
	ptr->Report();

	// Make ptr point to Classic Object
	*ptr = c2;

	// Call Report() using Cd type pointer containing Classic object address
	ptr->Report();

	return 0;
}
