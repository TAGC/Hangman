// LinkedList.h - written by Tag.
// Provides use of a linked-list data structure in the program.
// Used to store string objects only.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"

class LinkedNode;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	string getCurrentNodeValue()const;
	string getRandomNodeValue();  

	LinkedNode* getCurrentNode()const;

	void addValue(string newValue);
	void nextNode();
	void resetCurrentNode();
	int  length()const;
	void print();

private:
	int size; // Number of nodes sans the head.

	LinkedNode* head;
	LinkedNode* last;
	LinkedNode* current;
};

#endif
