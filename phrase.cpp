#include <iostream>
#include <fstream>
#include "phrase.h"
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

using namespace std;

namespace type_phrases {

	string phrase::Check_In_String(ifstream& ifst) {
		string temp = "";
		if (!ifst.eof()) {
			getline(ifst, temp);
			return temp;
		}
		else {
			cout << "|Input file ended|" << endl;
			return "0";
		}
	}

	phrase* phrase::Phrase_Input(ifstream& ifst) {
		phrase* newPhrase;
		string k = "";
		getline(ifst, k);
		if (k == "") {
			cout << "|Missing an empty string|" << endl;
			return 0;
		}
		else {
			switch (atoi(k.c_str())) {
			case 1:
				newPhrase = new aphorism;
				break;
			case 2:
				newPhrase = new proverb;
				break;
			case 3:
				newPhrase = new riddle;
				break;
			default:
				cout << "|There are no such type of phrases|" << endl;
				for (unsigned short i = 0; i < 3; i++) {
					k = Check_In_String(ifst);
					if (k == "0") {
						break;
					}
				}
				return 0;
			}

			if (!newPhrase->Input(ifst)) {
				return 0;
			}
			if ((newPhrase->content = Check_In_String(ifst)) == "0") {
				return 0;
			}
			string ev = "";
			if ((ev = Check_In_String(ifst)) == "0") {
				return 0;
			}
			try {
				newPhrase->eval = stoi(ev);
				if (newPhrase->eval < 0 || newPhrase->eval > 10) {
					cout << "|Evaluetion value is not in the range 0-10|" << endl;
					return 0;
				}
			}
			catch (invalid_argument e) {
				cout << "|Caught Invalid Argument Exception for evaluetion|" << endl;
				return 0;
			}
			return newPhrase;
		}
	}

	void phrase::Phrase_Output(ofstream& ofst) {
		ofst << "Content: " << content << "\n" << "Evaluation: " << eval << "." << endl;
	}

	unsigned short int phrase::Num_Punct_Marks() {
		string punctM = ".,;:\"!?()-";
		unsigned short int cnt = 0; // от 0 до 65535
		for (unsigned int i = 0; i < content.length(); i++) {
			for (unsigned j = 0; j < punctM.length(); j++) {
				if (content[i] == punctM[j]) {
					if (cnt > 65535) {
						return -1;
					}
					cnt++;
				}
			}
		}
		return cnt;
	}

	bool phrase::Compare(phrase* next) {
		return Num_Punct_Marks() > next->Num_Punct_Marks(); // в порядке неубывания
	}
	// Вывод данных только для афоризмов
	bool phrase::Output_Aphorism(ofstream& ofst) {
		ofst << endl;
		return false;
	}
}