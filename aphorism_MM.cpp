#include <iostream>
#include <fstream>
#include "aphorism.h"

namespace type_phrases {

	void aphorism::MultiMethod(phrase* other, ofstream& ofst) {
		other->MMAphorism(ofst);
	}

	void aphorism::MMAphorism(ofstream& ofst) {
		ofst << "Aphorism and Aphorism" << endl;
	}

	void aphorism::MMProverb(ofstream& ofst) {
		ofst << "Proverb and Aphorism" << endl;
	}
}