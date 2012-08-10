// LinkedNode.h - written by Tag.
// Works with LinkedList.

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "HangmanUtil.h"

class LinkedNode
{
public:
	LinkedNode(string value);
	~LinkedNode();

	string      getValue()const;
	LinkedNode* getNextNode()const;
	void        setNextNode(LinkedNode* next);
	void        print();

private:
	string      value;
	LinkedNode* next;
};

#endif