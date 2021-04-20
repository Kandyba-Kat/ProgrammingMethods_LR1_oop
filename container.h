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
		node* tmpNode = new node;
	public:
		void Cont_Clear();
		void Cont_Fill(ifstream& ifst);
		void Cont_Output(ofstream& ofst);
		void Cont_Output_Aphos(ofstream& ofst);

		void MultiMethod(ofstream& ofst);

		node* Get_Node(int index);
		void Swap(int index_first, int index_second);
		void Sort();

		int Get_Size() { 
			return size; 
		};

		container();
		~container();
	};
} // end type_phrases namespace

#endif // !CONTAINER_H

