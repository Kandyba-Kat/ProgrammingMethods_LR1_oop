#include <iostream>
#include <fstream>
#include "proverb.h"

namespace type_phrases {

	void proverb::MultiMethod(phrase* other, ofstream& ofst) {
		other->MMProverb(ofst);
	}

	void proverb::MMAphorism(ofstream& ofst) {
		ofst << "\tAphorism and Proverb" << endl;
	}

	void proverb::MMProverb(ofstream& ofst) {
		ofst << "\tProverb and Proverb" << endl;
	}

	void proverb::MMRiddle(ofstream& ofst) {
		ofst << "\tRiddle and Proverb" << endl;
	}
}