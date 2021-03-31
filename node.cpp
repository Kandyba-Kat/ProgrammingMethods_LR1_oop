#include <iostream>
#include <fstream>
#include "node.h"

using namespace std;

namespace type_phrases {

	bool node::node_Add(ifstream& ifst) {
		info = phrase::phrase_Input(ifst);
		if (info == NULL) return false;
		else return true;
	}

	bool node::node_Output(ofstream& ofst) {
		if (info->OutputAphorism(ofst))
			info->phrase_Output(ofst);
		return true;
	}

	node* node::node_Next(node* cur_node, node* value, int flag) {
		switch (flag)
		{
		case 1: // �������� ������ �� ��������� �������
			cur_node->next = value;
			return cur_node;
		case 2: // �������� ��������� �������
			cur_node = cur_node->next;
			return cur_node;
		default:
			break;
		}
	}

	node* node::node_Prev(node* cur_node, node* value, int flag) {
		switch (flag)
		{
		case 1: // �������� ������ �� ���������� �������
			cur_node->prev = value;
			return cur_node;
		case 2: // �������� ���������� �������
			cur_node = cur_node->prev;
			return cur_node;
		default:
			break;
		}
	}

	void node::node_Init(node* cur_node, int size_list) {
		cur_node->next = NULL;
		if (size_list == 0) cur_node->prev = NULL;
	}

	node::~node() {}
}