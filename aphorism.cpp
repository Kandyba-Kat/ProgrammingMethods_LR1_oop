#include <iostream>
#include <fstream>
#include "aphorism.h"

using namespace std;

namespace type_phrases {

	void aphorism::Input(ifstream& ifst) {
		getline(ifst, author);
	}

	void aphorism::Output(ofstream& ofst) {
		ofst << "Author of aphorism: " << author << ";" << endl;
	}

	bool aphorism::OutputAphorism(ofstream& ofst) {
		Output(ofst);
		return true;
	}

	aphorism::~aphorism() {}
}