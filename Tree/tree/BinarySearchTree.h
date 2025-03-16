#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class BinarySearchTree
{
private:
	Node* root;
public:
	BinarySearchTree() {
		root = nullptr;
	}
	bool insert(int value) {
		Node* newNode = new Node(value);
		if (!root) {
			root = newNode;
			return true;
		}
		Node* temp = root;
		while (true)
		{
			if (temp->value == newNode->value) {
				return false;
			}
			if (temp->value > newNode->value) {
				if (temp->left) {
					temp=temp->left;
				}
				else {
					temp->left = newNode;
					return true;
				}
				
			}
			if (temp->value < newNode->value) {
				if (temp->right) {
					temp = temp->right;
				}
				else {
					temp->right = newNode;
					return true;
				}
			}
		}
	}
	bool contains(int value) {
		Node* temp = root;
		while (temp) {
			if (value < temp->value) {
				temp = temp->left;
			}
			else if(value > temp->value) {
				temp = temp->right;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

