#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class Stack
{
private:
	Node* top;
	int height=0;
public:
	Stack(int value) {
		Node* newNode = new Node(value);
		top = newNode;
		height++;
	}
	void printStack() {
		Node* temp = top;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		height++;
	}
	int pop() {
		if (height == 0) {
			return INT_MIN;
		}
		Node* temp = top;
		int popedValue = top->value;
		top = top->next;
		delete temp;
		height--;
		return popedValue;
	}
};

