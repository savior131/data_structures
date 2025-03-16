#pragma once
#include <iostream>;
#include "Node.h"
using namespace std;
class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	int length=0;

public:
	DoublyLinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length++;
	}
	void printList() {
		Node* temp = head;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
	void append(int value) {
		Node* newNode = new Node(value);
		if (length==0) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		length++;
	}
	void deleteLast() {
		if (length == 0) {
			return;
		}
		Node* temp=tail;
		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}
		delete temp;
		length--;
	}
	void prepend(int value) {
		Node* newNode = new Node(value);
		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void deleteFirst() {
		if (length == 0) {
			return;
		}
		Node* temp=head;
		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
		length--;
	}
	Node* get(int index) {
		if (index < 0 || index >= length) {
			return nullptr;
		}
		Node* temp;
		if (index < length / 2) { //3    5
			temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
		}
		else {
			temp =tail;
			for (int i = length-1; i >index; i--) {
				temp = temp->prev;
			}
		}
		return temp;
	}
	bool set(int index, int value) {
		Node* temp = get(index);
		if (temp) {
			temp->value = value;
			return true;
		}
		return false;

	}
	bool insert(int index, int value) {
		if (index<0 || index>length) {
			return false;
		}
		if (index == 0) {
			prepend(value);
			return true;
		}
		if (index == length) {
			append(value);
			return true;

		}
		Node* prev = get(index - 1);
		Node* temp = prev->next;
		Node* newNode = new Node(value);
		prev->next = newNode;
		temp->prev = newNode;
		newNode->next = temp;
		newNode->prev = prev;
		length++;
		return true;
	}
	void deleteNode(int index) {
		if (index < 0 || index >= length) {
			return;
		}
		if (index == 0) {
			return deleteFirst();
		}
		if (index == length - 1) {
			return deleteLast();
		}
		Node* temp = get(index);
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
		length--;
		return;
	}
	void swapFirstLast() {
		int temp = tail->value;
		tail->value = head->value;
		head->value = temp;
	}
	void reverse() {
		if (length < 2) {
			return;
		}
		Node* current=head;
		Node* temp;
		for (int i = 0; i < length;i++) {
			temp = current->next;
			current->next = current->prev;
			current->prev = temp;
			current = current->prev;
		}
		temp=head;
		head = tail;
		tail = temp;
	}
	bool isPalindrome() {
		if (length < 2) {
			return true;
		}
		Node* last = tail;
		Node* first = head;
		for (int i = 0; i < length / 2; i++) {
			if (last->value != first->value) {
				return false;
			}
			last = last->prev;
			first = first->next;

		}
		return true;
	}
	void swapPairs() {
		if (length < 2) {
			return;
		}
		Node* temp = head->next;
		while (temp) {
			int tempVal = temp->value;
			temp->value = temp->prev->value;
			temp->prev->value = tempVal;
			temp = temp->next;
			if (temp) {
				temp=temp->next;
			}
			else {
				return;
			}
		}
	}
};

