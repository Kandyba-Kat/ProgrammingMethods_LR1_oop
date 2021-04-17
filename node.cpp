#include <iostream>
#include <fstream>
#include "node.h"

using namespace std;

namespace type_phrases {

	bool node::Node_Add(ifstream& ifst) {
		info = phrase::Phrase_Input(ifst);
		if (info == NULL) {
			return false;
		}
		else {
			return true;
		}
	}

	bool node::Node_Output(ofstream& ofst) {
		info->Output(ofst);
		info->Phrase_Output(ofst);
		unsigned short int check = info->Num_Punct_Marks();
		if (check == -1) {
			cout << "|Overflow of number of punctuation marks|" << endl;
			ofst << "Overflow of number of punctuation marks." << endl;
			exit(1);
		}
		else {
			ofst << "Number of punctuation marks: " << check << "." << endl;
		}
		return true;
	}

	bool node::Node_Out_Aphos(ofstream& ofst) {
		if (info->Output_Aphorism(ofst)) {
			info->Phrase_Output(ofst);
			int check = info->Num_Punct_Marks();
			if (check == -1) {
				cout << "|Overflow of number of punctuation marks|" << endl;
				ofst << "Overflow of number of punctuation marks." << endl;
				exit(1);
			}
			else {
				ofst << "Number of punctuation marks: " << check << "." << endl;
			}
		}
		return true;
	}

	node* node::Node_Next(node* cur_node, node* value, int flag) {
		switch (flag) {
		case 1: // добавить ссылку на следующий элемент
			cur_node->next = value;
			return cur_node;
		case 2: // получить следующий элемент
			cur_node = cur_node->next;
			return cur_node;
		default:
			break;
		}
	}

	node* node::Node_Prev(node* cur_node, node* value, int flag) {
		switch (flag) {
		case 1: // добавить ссылку на предыдущий элемент
			cur_node->prev = value;
			return cur_node;
		case 2: // получить предыдущий элемент
			cur_node = cur_node->prev;
			return cur_node;
		default:
			break;
		}
	}

	void node::Node_Init(node* cur_node, int size_list) {
		cur_node->next = NULL;
		if (size_list == 0) {
			cur_node->prev = NULL;
		}
	}

	phrase* node::Get_Info() {
		return info;
	}

	void node::Set_Info(phrase* value) {
		info = value;
	}

	node::~node() {}
}