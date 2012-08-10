#include "LinkedList.h"

LinkedList::LinkedList()
:size(0)
{
	LinkedNode* firstNode = new LinkedNode("Empty");

	firstNode->setNextNode(NULL);
	head = firstNode;
	last = firstNode;
	current = firstNode;

	srand((unsigned int)time(NULL));
}

LinkedList::~LinkedList()
{
	delete head;
	head = NULL;
	last = NULL;
	current = NULL;
}

void LinkedList::addValue(string newValue)
{
	LinkedNode* newNode = new LinkedNode(newValue);
	newNode->setNextNode(NULL);

	last->setNextNode(newNode);
	last = newNode;

	size++;
}

void LinkedList::nextNode()
{
	if(current->getNextNode() != NULL)
	{
		current = current->getNextNode();
	}
}

void LinkedList::resetCurrentNode()
{
	current = head;
}

string LinkedList::getCurrentNodeValue()const
{
	return current->getValue();
}

string LinkedList::getRandomNodeValue()
{
	LinkedNode* oldCurrent;
	string      value;
	int         listIndex;

	oldCurrent = current;

	resetCurrentNode();
	nextNode(); // Move past the head.

	// Increases apparent randomness of values.
	for(int i=0; i < int(20*((float)rand()/(float)RAND_MAX)+20); i++)
	{
		rand();
	}

	listIndex = int( ((float)rand()/(float)RAND_MAX) * length() );
	
	for(int i=0; i < listIndex; i++)
	{
		//cout << "Current node address: " << current << endl;
		nextNode();
	}

	value = getCurrentNodeValue();
	current = oldCurrent;

	return value;
}

LinkedNode* LinkedList::getCurrentNode()const
{
	return current;
}

int LinkedList::length()const
{
	return size;
}

void LinkedList::print()
{
	LinkedNode* oldCurrent;
	oldCurrent = current;

	cout << "Printing list...\n";
	resetCurrentNode();
	for(int i=0; i < length(); i++)
	{
		nextNode();
		getCurrentNode()->print();
	}

	current = oldCurrent;
}