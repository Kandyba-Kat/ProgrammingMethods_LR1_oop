#ifndef PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// общий класс фраз
	class phrase {
		string content;
	public:
		virtual ~phrase() {};
		static phrase* phrase_Input(ifstream& ifst);
		void phrase_Output(ofstream& ofst);
		virtual void Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		// мультиметод
		virtual void MultiMethod(phrase* other, ofstream& ofst) = 0;
		virtual void MMAphorism(ofstream& ofst) = 0;
		virtual void MMProverb(ofstream& ofst) = 0;
	};
} // end type_phrases namespace

#endif // !PHRASE_H

