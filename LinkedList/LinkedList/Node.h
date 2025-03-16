#pragma once
class Node
{
public:
	string key;
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}
	Node(string key,int value) {
		this->key = key;
		this->value = value;
		next = nullptr;
	}
	
};

