#include <iostream>
#include <fstream>
#include "phrase.h"
#include "aphorism.h"
#include "proverb.h"

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
		default:
			cout << "There are no such type of phrases!" << endl;
			return 0;
		}
		new_phrase->Input(ifst);
		getline(ifst, new_phrase->content);
		return new_phrase;
	}

	void phrase::phrase_Output(ofstream& ofst) {
		ofst << "Content: " << content << endl;
	}

	int phrase::num_punct_marks() {
		string punctM = ".,;:\"!?()-";
		int cnt = 0;
		for (int i = 0; i < content.length(); i++) {
			for (int j = 0; j < punctM.length(); j++) {
				if (content[i] == punctM[j]) {
					cnt++;
				}
			}
		}
		return cnt;
	}

	bool phrase::compare(phrase* next)
	{
		return num_punct_marks() > next->num_punct_marks(); // � ������� ����������
	}
}