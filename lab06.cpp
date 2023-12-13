//============================================================================
// Name        : CSCI1061U_lab06.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Practicing inheritance and polymorphism using multiple classes.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//The Classes
class Student {
protected:
	vector<string> levels;

public:
	Student() {levels = {};};

	void addToVector(string level) {
		levels.push_back(level);
	}

	vector<string>& getStudyLevels() {
		return levels;
	}
};

class Undergraduate : public Student {
public:
	Undergraduate() {levels = {};};
};

class Graduate : public Student {
public:
	Graduate() {levels = {};};
};


//get number of each study level
int* getLevels(vector<Student*>& v) {

	//array with two numbers, index 0 holds number of undergrads
	//index 1 holds number of graduates
	int* num_levels = new int[2];
	num_levels[0] = 0;
	num_levels[1] = 0;

	for (Student* s : v) {

		Student deref_s = *s;

		if (deref_s.getStudyLevels()[0] == "undergraduate") {
			num_levels[0] ++;
		}

		else {
			num_levels[1] ++;
		}
	}

	return num_levels;
}


void assignStudents(vector<Student*>& v) {

	string level;

	for (int i = 0; i < 10; i++) {
		cout << "Enter a study level: ";
		cin >> level;

		if (level == "undergraduate") {

			Undergraduate* undergrad = new Undergraduate;
			Student* student = undergrad;
			student->addToVector(level);
			v.push_back(student);

		}

		else if (level == "graduate") {

			Graduate* grad = new Graduate;
			Student* student = grad;
			student->addToVector(level);
			v.push_back(student);

		}

		else {
			cout << "That was not a valid study level, please re-enter" << endl;
			i--;
		}
	}

	cout << "Undergraduate: " << getLevels(v)[0] << "\nGraduate: " << getLevels(v)[1] << endl;
}


int main() {

   vector<Student*> v;

   assignStudents(v);


   return 0;

}
