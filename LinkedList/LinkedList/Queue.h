#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class Queue
{
private:
	Node* first;
	Node* last;
	int length=0;
public:
	Queue(int value) {
		Node* newNode = new Node(value);
		first = newNode;
		last = newNode;
		length++;
	}
	void printQueue() {
		Node* temp = first;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
	void enqueue(int value) {
		Node* newNode = new Node(value);
		if (length == 0) {
			last = newNode;
			first = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		length++;
	}
	int dequeue() {
		if (length == 0) {
			return INT_MIN;
		}
		int dequeuedVal = first->value;
		Node* temp = first;
		if (length == 1) {
			first=nullptr;
			last =nullptr;
		}
		else {
			first = first->next;
		}
		delete temp;
		length--;
		return dequeuedVal;
	}
};

