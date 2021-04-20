#include <iostream>
#include <fstream>
#include "riddle.h"

namespace type_phrases {

	void riddle::MultiMethod(phrase* other, ofstream& ofst) {
		other->MMRiddle(ofst);
	}

	void riddle::MMAphorism(ofstream& ofst) {
		ofst << "\tAphorism and Riddle" << endl;
	}

	void riddle::MMProverb(ofstream& ofst) {
		ofst << "\tProverb and Riddle" << endl;
	}

	void riddle::MMRiddle(ofstream& ofst) {
		ofst << "\tRiddle and Riddle" << endl;
	}
}