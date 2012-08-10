#include "LinkedNode.h"

LinkedNode::LinkedNode(string value)
{
	this->value = value;
}

LinkedNode::~LinkedNode()
{
	delete next;
	next = NULL;
}

string LinkedNode::getValue()const
{
	return value;
}

void LinkedNode::setNextNode(LinkedNode* next)
{
	this->next = next;
}

LinkedNode* LinkedNode::getNextNode()const
{
	return next;
}

void LinkedNode::print()
{
	cout << value << endl;
}