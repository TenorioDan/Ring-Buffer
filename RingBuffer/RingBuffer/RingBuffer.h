#pragma once

/* 
* Ring Buffer will be a template class that can take an int of 
* as its values.
* Each buffer will be initialized with a size, n, and will contain
* n nodes, each containing a value and a pointer to the next node.
*/
class RingBuffer 
{
public:
	RingBuffer(int);
	~RingBuffer();
	void add(int);
	int size();
	int average();


private:
	class Node
	{
	public:
		Node() {};
		Node* next;
		int value = 0;
		//friend std::ostream& operator<<(std::ostream& os, Node n) { std::cout << n.value; };
	};

	int count;
	Node* write;
};