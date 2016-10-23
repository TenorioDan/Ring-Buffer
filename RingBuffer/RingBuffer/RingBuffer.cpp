#include "RingBuffer.h"
#include <iostream>

RingBuffer::RingBuffer(int n)
	: count(n)
{
	if (count) 
	{
		Node* currentNode = new Node();
		Node& firstNode = *currentNode;

		// create all of the nodes in buffer
		// it does not matter where in the buffer we start adding values
		for (int i = 0; i < n-1; ++i)
		{
			Node* node = new Node();
			currentNode->next = node;
			currentNode = node;
		}

		currentNode->next = &firstNode;
		write = &firstNode;
	}
}

// add a value to the current write pointer
void RingBuffer::enqueue(int value)
{
	//std::cout << "old value: " << write->value;
	write->value = value;
	//std::cout << " - new value: " << write->value << std::endl;
	write = write->next;
	//std::cout << " next value: " << write->value << std::endl;
}


// return the size of the buffer, not the number of elements
// that are in it but the total number nodes in the buffer
int RingBuffer::size()
{
	return count;
}


// Traverse the nodes, summing them and return the averages of 
// them
int RingBuffer::average()
{
	Node* currentNode = write->next;
	int sum = write->value;
	
	while (currentNode != write)
	{
		sum += currentNode->value;
		currentNode = currentNode->next;
	}

	return sum/count;
}


// Traverse the nodes and delete each one
RingBuffer::~RingBuffer()
{
	Node* currentNode = write->next;
	delete write;

	while (currentNode != write)
	{
		Node* previousNode = currentNode;
		currentNode = currentNode->next;
		delete previousNode;
	}
}