#ifndef CONTAINER_H
#define CONTAINER_H
#include <fstream>
#include <string>
#include "node.h"

using namespace std;

namespace type_phrases {
	class container {
		int size;
		node* head; // pointer to the first item in the list
		node* tail;
		node* tmp_node = new node;
	public:
		void container_Clear();
		void container_Fill(ifstream& ifst);
		void container_Output(ofstream& ofst);
		void MultiMethod(ofstream& ofst);
		container();
		~container();
	};
} // end type_phrases namespace

#endif // !CONTAINER_H

