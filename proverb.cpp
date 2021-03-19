#include <iostream>
#include <fstream>
#include "proverb.h"

using namespace std;

namespace type_phrases {

	void proverb::Input(ifstream& ifst) {
		getline(ifst, country);
	}

	void proverb::Output(ofstream& ofst) {
		ofst << "Proverb of country: " << country << ";" << endl;
	}

	proverb::~proverb() {}
}