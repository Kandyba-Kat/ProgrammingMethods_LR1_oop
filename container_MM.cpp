#include <iostream>
#include <fstream>
#include "container.h"

namespace type_phrases {
	void container::MultiMethod(ofstream& ofst) {
		ofst << "Multimethod." << endl;
		node* node1 = head;
		node* node2;
		for (int i = 0; i < size - 1; i++) {
			node2 = node::Node_Next(node1, NULL, 2);
			for (int j = i + 1; j < size; j++) {
				node1->Get_Info()->MultiMethod(node2->Get_Info(), ofst);
				node1->Node_Output(ofst);
				node2->Node_Output(ofst);
				node2 = node::Node_Next(node2, NULL, 2);
			}
			node1 = node::Node_Next(node1, NULL, 2);
		}
	}
}