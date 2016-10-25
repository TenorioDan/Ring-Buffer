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

	// test a smaller buffer
	RingBuffer buffer2(3);
	buffer2.add(4);
	buffer2.add(5);
	buffer2.add(6);
	assert(buffer2.average() == 5);
	std::cout << "average: " << buffer2.average() << std::endl;

	// test larger buffer
	RingBuffer buffer3(15);
	buffer3.add(14);
	buffer3.add(25);
	buffer3.add(26);
	buffer3.add(44);
	buffer3.add(8);
	buffer3.add(90);
	buffer3.add(21);
	buffer3.add(37);
	buffer3.add(9);
	buffer3.add(42);
	buffer3.add(65);
	buffer3.add(77);
	buffer3.add(19);
	buffer3.add(12);
	buffer3.add(6);
	assert(buffer3.average() == 33);
	std::cout << "average: " << buffer3.average() << std::endl;

	// test larger buffer with some empty elements
	RingBuffer buffer4(15);
	buffer4.add(14);
	buffer4.add(25);
	buffer4.add(26);
	buffer4.add(44);
	buffer4.add(8);
	buffer4.add(90);
	buffer4.add(21);
	buffer4.add(37);
	buffer4.add(9);
	assert(buffer4.average() == 18);
	std::cout << "average: " << buffer4.average() << std::endl;

	return 0;
}