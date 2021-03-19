#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;

namespace type_phrases {

	void container::container_Fill(ifstream& ifst) {
		if (head != NULL) {
			cout << "|List is not empty!|" << endl;
			return;
		}
		if (tmp_node->node_Add(ifst)) {
			head = tmp_node;
			tail = tmp_node;
			/*node::node_Next(tmp_node, NULL, 1);
			tmp_node->next = NULL;
			node::node_Next(tmp_node, NULL, 2);
			tmp_node->prev = NULL;*/
			tmp_node->node_Init(tmp_node, size);

			size++;
			tmp_node = NULL;
			tmp_node = new node;
		}
		while (tmp_node->node_Add(ifst)) {			
			/*node::node_Next(tmp_node, NULL, 1);
			tmp_node->next = NULL;*/
			tmp_node->node_Init(tmp_node, size);

			node::node_Prev(tmp_node, tail, 1);
			//tmp_node->prev = tail;
			node::node_Next(tail, tmp_node, 1);
			//tail->next = tmp_node;

			tail = tmp_node;
			size++;
			tmp_node = NULL;
			tmp_node = new node;
		}
		delete(tmp_node);
	}

	void container::container_Output(ofstream& ofst) {
		if (size == 0) {
			cout << "|List is empty!|" << endl;
			return;
		}
		ofst << "Container contains " << size << " element" << endl;
		cout << "|Container contains " << size << " elements.|" << endl;
		tmp_node = head;
		for (int i = 0; i < size; i++) {
			tmp_node->node_Output(ofst);
			tmp_node = node::node_Next(tmp_node, NULL, 2);
			//tmp_node = tmp_node->next;
		}
	}

	void container::container_Clear() {
		if (head == NULL) return;
		else {
			for (int i = 0; i < size; i++) {
				tmp_node = tail;
				tail = node::node_Prev(tail, NULL, 2);
				//tail = tail->prev;
				tmp_node->~node();
			}
			size = 0;
			head = NULL;
			tail = NULL;
		}
	}

	container::container() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	container::~container() {
		container_Clear();
	}
}