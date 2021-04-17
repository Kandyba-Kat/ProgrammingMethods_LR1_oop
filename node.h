#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <string>
#include "phrase.h"
using namespace std;

namespace type_phrases {
	class node {
		phrase* info;
		node* next;
		node* prev;
	public:
		bool Node_Add(ifstream& ifst);
		bool Node_Output(ofstream& ofst);
		bool Node_Out_Aphos(ofstream& ofst);
		static node* Node_Next(node* cur_node, node* value, int flag);
		static node* Node_Prev(node* cur_node, node* value, int flag);
		void Node_Init(node* cur_node, int size_list);
		phrase* Get_Info();
		void Set_Info(phrase* value);
		~node();
	};
} // end type_phrases namespace

#endif // !NODE_H

