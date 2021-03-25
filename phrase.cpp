#include <iostream>
#include <fstream>
#include "phrase.h"
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

using namespace std;

namespace type_phrases {

	phrase* phrase::phrase_Input(ifstream& ifst) {
		phrase* new_phrase;
		string k;
		getline(ifst, k);
		if (k == "") return 0;
		switch (atoi(k.c_str()))
		{
		case 1:
			new_phrase = new aphorism;
			break;
		case 2:
			new_phrase = new proverb;
			break;
		case 3:
			new_phrase = new riddle;
			break;
		default:
			cout << "There are no such type of phrases!" << endl;
			return 0;
		}
		new_phrase->Input(ifst);
		getline(ifst, new_phrase->content);
		return new_phrase;
	}

	void phrase::phrase_Output(ofstream& ofst) {
		ofst << "Content: " << content << "." << endl;
	}
}