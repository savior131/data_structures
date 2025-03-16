#pragma once
class Node
{
public:
	Node* left;
	Node* right;
	int value;
	Node(int value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

