#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

namespace type_phrases {

	void container::Cont_Fill(ifstream& ifst) {
		if (head != NULL) {
			cout << "|List is not empty|" << endl;
			return;
		}

		while (!ifst.eof()) {
			if (tmpNode->Node_Add(ifst)) {
				if (size == 0) {
					head = tmpNode;
					tail = tmpNode;
				}
				tmpNode->Node_Init(tmpNode, size);
				if (size > 0) {
					node::Node_Prev(tmpNode, tail, 1);
					node::Node_Next(tail, tmpNode, 1);
					tail = tmpNode;
				}				
				size++;
				tmpNode = NULL;
				tmpNode = new node;
			}
			else {
				cout << "|Addition node #" << (size + 1) << " failed|" << endl;
			}			
		}
		delete(tmpNode);
	}

	void container::Cont_Output(ofstream& ofst) {
		if (size == 0) {
			cout << "|Container output failed. It's empty|" << endl;
			return;
		}
		ofst << "Container contains " << size << " element" << endl;
		cout << "|Container contains " << size << " elements|" << endl;
		tmpNode = head;
		for (int i = 0; i < size; i++) {
			ofst << (i+1) << ": ";
			if (tmpNode->Node_Output(ofst)) {
				tmpNode = node::Node_Next(tmpNode, NULL, 2);
			}
			else {
				cout << "|Error in node #" << i+1 << " output|" << endl;
			}
		}
	}

	void container::Cont_Output_Aphos(ofstream& ofst) {
		if (size == 0) {
			cout << "|Container output failed. It's empty|" << endl;
			return;
		}
		tmpNode = head;
		ofst << "Only Aphorism." << endl;
		for (int i = 0; i < size; i++) {
			ofst << (i + 1) << ": ";
			tmpNode->Node_Out_Aphos(ofst);
			tmpNode = node::Node_Next(tmpNode, NULL, 2);
		}
	}

	void container::Cont_Clear() {
		if (head == NULL) {
			cout << "|Container cleanup failed. It's empty|" << endl;
			return;
		}
		else {
			for (int i = 0; i < size; i++) {
				tmpNode = tail;
				tail = node::Node_Prev(tail, NULL, 2);
				tmpNode->~node();
			}
			size = 0;
			head = NULL;
			tail = NULL;
		}
	}

	node* container::Get_Node(int index) {
		node* returnedNode = head;
		for (int i = 0; i < index; i++) {
			returnedNode = node::Node_Next(returnedNode, NULL, 2);
		}
		return returnedNode;
	}

	void container::Swap(int index_first, int index_second) {
		node* temp = new node;
		temp->Set_Info(Get_Node(index_first)->Get_Info());
		Get_Node(index_first)->Set_Info(Get_Node(index_second)->Get_Info());
		Get_Node(index_second)->Set_Info(temp->Get_Info());
	}

	void container::Sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (Get_Node(i)->Get_Info()->Compare(Get_Node(j)->Get_Info()))
				{
					Swap(i, j);
				}
			}
		}
	}

	container::container() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	container::~container() {
		Cont_Clear();
	}
}