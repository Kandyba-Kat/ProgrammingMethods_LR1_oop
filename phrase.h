#ifndef PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// общий класс фраз
	class phrase {
		string content;
		short eval;
	public:
		virtual ~phrase() {};
		static phrase* Phrase_Input(ifstream& ifst);
		void Phrase_Output(ofstream& ofst);
		virtual bool Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		unsigned short int Num_Punct_Marks();
		bool Compare(phrase* next);		
		virtual bool Output_Aphorism(ofstream& ofst); // Вывод только афоризмов
		static string Check_In_String(ifstream& ifst);

		// мультиметод
		virtual void MultiMethod(phrase* other, ofstream& ofst) = 0;
		virtual void MMAphorism(ofstream& ofst) = 0;
		virtual void MMProverb(ofstream& ofst) = 0;
		virtual void MMRiddle(ofstream& ofst) = 0;
	};
} // end type_phrases namespace

#endif // !PHRASE_H

