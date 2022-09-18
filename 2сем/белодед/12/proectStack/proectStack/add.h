#pragma once

#include <iostream>
struct Node {
	int data;
	Node* left, * right;
};

void insert(int a, Node** t);
void print(Node* t, int u);
Node* search(Node* t, int k);
