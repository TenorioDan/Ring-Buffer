#include "RingBuffer.h"
#include <iostream>

int main()
{
	RingBuffer buffer(5);
	buffer.enqueue(5);
	buffer.enqueue(6);
	buffer.enqueue(7);
	buffer.enqueue(8);
	buffer.enqueue(9);
	buffer.enqueue(10);
	buffer.enqueue(11);
	std::cout << "average: " << buffer.average() << std::endl;
	return 0;
}