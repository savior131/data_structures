#pragma once
#include <iostream>
#include "Node.h"
#include<vector>
#include<unordered_map>
using namespace std;
class HashTable
{
private:
	static const int SIZE = 7;
	Node* dataMap[SIZE];

	int hash(string key) {
		int hash = 0;
		for (int i = 0; i < key.length(); i++) {
			int asciiValue = int(key[i]);
			hash = (hash + asciiValue * 23) % SIZE;
		}
		return hash;
	}
public:
	
	void set(string key, int value) {
		int index=hash(key);
		Node* newNode = new Node(key, value);
		if (!dataMap[index]) {
			dataMap[index] = newNode;
		}
		else {
			Node* temp = dataMap[index];
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	int get(string key) {
		int index = hash(key);
		Node* temp = dataMap[index];
		while (temp) {
			if (temp->key==key) {
				return temp->value;
			}
			temp = temp->next;
		}
		return INT_MIN;
	}
	vector<string> key() {
		vector<string> keys;
		for (int i = 0; i < SIZE; i++) {
			Node* temp = dataMap[i];
			while (temp) {
				keys.push_back(temp->key);
				temp = temp->next;
			}
		}
		return keys;
	}
	bool itemInCommon(vector<int> vect1, vector<int> vect2) {
		unordered_map<int, bool> map;
		for (auto i : vect1) {
			map.insert({ i,true });
		}
		for (auto i : vect2) {
			if (map[i]) {
				return true;
			}
		}
		return false;
	}
};

