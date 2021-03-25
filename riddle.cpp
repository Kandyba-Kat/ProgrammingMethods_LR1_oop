#include <iostream>
#include <fstream>
#include "riddle.h"

using namespace std;

namespace type_phrases {

	void riddle::Input(ifstream& ifst) {
		getline(ifst, answer);
	}

	void riddle::Output(ofstream& ofst) {
		ofst << "Answer to riddle: " << answer << ";" << endl;
	}

	riddle::~riddle() {}
}