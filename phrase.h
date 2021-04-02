#ifndef PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// общий класс фраз
	class phrase {
		string content;
		int eval;
	public:
		virtual ~phrase() {};
		static phrase* phrase_Input(ifstream& ifst);
		void phrase_Output(ofstream& ofst);
		virtual void Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		int num_punct_marks();
	};
} // end type_phrases namespace

#endif // !PHRASE_H

