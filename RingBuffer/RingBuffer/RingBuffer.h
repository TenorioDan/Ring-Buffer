#pragma once

/* 
* Ring Buffer will be a template class that can take any type of 
* argument as its value.
* Each buffer will be initialized with a size, n, and will contain
* n nodes, each containing a value and a pointer to the next node.
*/
class RingBuffer 
{
protected:
	class Node
	{
	public:
		Node() {};
		Node* next;
		int value = 0;
		//friend std::ostream& operator<<(std::ostream& os, Node n) { std::cout << n.value; };
	};

public:
	RingBuffer(int);
	~RingBuffer();
	void enqueue(int);
	int size();
	int average();


private:
	int count;
	Node* write;
};