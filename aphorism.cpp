#include <iostream>
#include <fstream>
#include "aphorism.h"

using namespace std;

namespace type_phrases {

	bool aphorism::Input(ifstream& ifst) {
		if ((author = Check_In_String(ifst)) != "0") {
			return true;
		}
		else {
			return false;
		}
	}

	void aphorism::Output(ofstream& ofst) {
		ofst << "Author of aphorism: " << author << ";" << endl;
	}

	bool aphorism::Output_Aphorism(ofstream& ofst) {
		Output(ofst);
		return true;
	}

	aphorism::~aphorism() {}
}