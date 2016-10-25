#include "RingBuffer.h"
#include <iostream>
#include <cassert>

int main()
{
	// Create a ring buffer with 5 elements and enqueue all 10s
	RingBuffer buffer(5);
	buffer.add(10);
	buffer.add(10);
	buffer.add(10);
	buffer.add(10);
	buffer.add(10);
	assert(buffer.average() == 10);
	std::cout << "average: " << buffer.average() << std::endl;

	// Write over all elements of the original buffer
	buffer.add(1);
	buffer.add(2);
	buffer.add(3);
	buffer.add(4);
	buffer.add(5);
	assert(buffer.average() == 3);
	std::cout << "average: " << buffer.average() << std::endl;
	return 0;
}