#include "phrase.h"

using namespace std;

namespace type_phrases {
	int num_punct_marks(struct phrase* phrase) {
		string punctM = ".,;:\"!?()-";
		int cnt = 0;
		for (int i = 0; i < (phrase->getCont()).length() /*content.length()*/; i++) {
			for (int j = 0; j < punctM.length(); j++) {
				if ((phrase->getCont())[i] == punctM[j]) {
					cnt++;
				}
			}
		}
		return cnt;
	}
}