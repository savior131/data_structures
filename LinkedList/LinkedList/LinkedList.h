#pragma once
#include "Node.h"
#include<iostream>
using namespace std;
class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}
	~LinkedList() {
		Node* temp = head;
		while (temp) {
			head = head->next;
			delete temp;
			temp = head;
		}
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
		if (!tail) {
			head = newNode;
			tail = newNode;
	    }
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}
	void deleteLast() {
		if (length == 0) {
			return;
		}
		Node* temp = head;
		if (length == 1) {
			tail = nullptr;
			head = nullptr;
		}
		else{
			Node* pre = head;
			while (temp->next) {
				pre = temp;
				temp = temp->next;
			}
			tail = pre;
			tail->next = nullptr;

		}
		length--;
		delete temp;
		
	}
	void prepend(int value) {
		Node* newNode = new Node(value);
		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void deleteFirst() {
		if (length == 0) {
			return;
		}
		Node* temp = head;
		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete temp;
		length--;
	}
	Node* get(int index) {
		if (index < 0 || index >= length) {
			return nullptr;
		}
		Node* temp = head;
	    for (int i = 0; i < index; i++) {
		    temp = temp->next;
	    }
		return temp;
	}
	bool set(int value, int index) {
		Node* temp = get(index);
		if (temp) {
			temp->value = value;
			return true;
		}
		return false;
	}
	bool insert(int value,int index) {
		if (index<0 || index>length) {
			return false;
		}
		else if (index == 0) {
			prepend(value);
			return true;
		}
		else if (index == length) {
			append(value);
			return true;
		}
		else {
			Node* newNode = new Node(value);
			Node* temp = get(index - 1);
			newNode->next = temp->next;
			temp->next = newNode;
			length++;
			return true;

		}

	}
	void deleteNode(int index) {
		if (index<0 || index>=length) {
			return;
		}
		if (index == 0) {	
			return deleteFirst();
		}
		if (index == length) {
			return deleteLast();
		}
		Node* prev = get(index - 1);
		Node* temp = prev->next;
		prev->next = temp->next;
		delete temp;
		length--;
	}
	void reverse() {
		Node* temp=head;
		head = tail;
		tail = temp;
		Node* before = nullptr;
		Node* after = temp->next;
		for (int i = 0; i < length; i++) {
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
	}
	Node* findMiddleNode(){
		Node* slow = head;
		Node* fast = head;
		while (fast) {
			fast = fast->next;
			if (!fast) {
				return slow;
			}
			else {
				fast = fast->next;
			}
			slow = slow->next;
		}
		return slow;
	}
	bool hasLoop() {
		Node* fast = head;
		Node* slow = head;
		while (fast) {
			fast = fast->next;
			if (fast) {
				fast = fast->next;
			}
			else {
				return false;
			}
			slow = slow->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
	Node* findKthFromEnd(int k) {
		Node* temp = head;
		int length = 0;
		while (temp) {
			temp = temp->next;
			length++;
		}
		temp = head;
		if (k > length) {
			return nullptr;
		}
		for (int i = 0; i < length-k; i++) {
			temp = temp->next;
		}
		return temp;
	}
	void partitionList(int x) {
		Node* firstList = nullptr;
		Node* secondList = nullptr;
		Node* temp = head;
		Node* temp1 = nullptr;
		Node* temp2 = nullptr;

		while (temp) {
			if (temp->value >= x) {
				if (!secondList) {
					secondList = temp;
					temp2 = secondList;
				}
				else {
					temp2->next = temp;
					temp2 = temp2->next;
				}
			}
			else {
				if (!firstList) {
					firstList = temp;
					temp1 = firstList;
				}
				else {
					temp1->next = temp;
					temp1 = temp1->next;
				}
			}
			temp = temp->next;
		}

		if (!firstList) {
			head = secondList;
		}
		else {
			temp1->next = secondList;
			head = firstList;
		}

		if (temp2) {
			temp2->next = nullptr;
		}
	}
	void removeDuplicates() {
		if (!head || !head->next) {
			return;
		}
		Node* slow=head;
		Node* fast=head->next;
		Node* prev = head;
		Node* temp=nullptr;
		while (fast) {
			if (fast->value == slow->value) {
				temp = fast;
				fast = fast->next;
				prev->next = fast;
				delete temp;
				length--;
			}
			else {
				fast = fast->next;
				prev = prev->next;
			}
			if (!fast) {
				slow = slow->next;
				if (!slow)return;
				prev = slow;
				fast = slow->next;
			}
			

		}
	}
	int binaryToDecimal() {
		int num = 0;
		Node* temp = head;
		for (int i = 0; i < length; i++) {
			if (temp->value==1) {
				int pow = 1;
				for (int j = 0; j < length-i-1; j++) {
					pow *= 2;
				}
				num+=pow;
			}
		temp = temp->next;
		}
		return num;
	}
	void reverseBetween(int m, int n) {
		if (head == nullptr) return;

		Node* dummy = new Node(0);
		dummy->next = head;
		Node* prev = dummy;

		for (int i = 0; i < m; i++) {
			prev = prev->next;
		}

		Node* current = prev->next;
		for (int i = 0; i < n - m; i++) {
			Node* temp = current->next;
			current->next = temp->next;
			temp->next = prev->next;
			prev->next = temp;
		}

		head = dummy->next;
		delete dummy;
	}


	Node* getHead() {
		return head;
	}
	Node* getTail() {
		return tail;
	}
	int getLength() {
		return length;
	}
};

