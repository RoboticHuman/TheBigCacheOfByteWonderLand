#include <iostream>
#include "cacheSim.h"
using namespace std;

cacheSim::cacheSim(int cachelineSize, int cacheSize, int memorySize, bool isFullyAssociative)
{
	this->cachelineSize = cachelineSize;
	this->cacheSize = cacheSize;
	this->memorySize = memorySize;
	cType = cacheType(isFullyAssociative);
	numberOfCachelines = cacheSize / cachelineSize;

	cache = new cacheline[numberOfCachelines](cachelineSize);
	
	
	
	
	
	cout << typestr[cType] << " Cache Simulator\n";
	for (int inst = 0; inst<100; inst++)
	{
		unsigned int addr = memGenRandom();
		condition r = cacheSimDM(addr);
		cout << addr << " (" << condStr[r] << ")\n";
	}
}


unsigned int cacheSim::memGenSeq()
{
	static unsigned int addr = 0;
	return (addr++) % (1024 * 1024);
}

unsigned int cacheSim::memGenRandom()
{
	return rand() % (1024 * 1024);
}

unsigned int cacheSim::memGenLoop1()
{
	static unsigned int addr = 0;
	return (addr++) % (1024 * 4);
}

unsigned int cacheSim::memGenLoop2()
{
	static unsigned int addr = 0;
	return (addr++) % (1024 * 24);
}


// Direct Mapped Cache Simulator
condition cacheSim::cacheSimDM(unsigned int addr)
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	// The current implementation assumes there is no cache; so, every transaction is a miss
	return MISS;
}

// Fully Associative Cache Simulator
condition cacheSim::cacheSimFA(unsigned int addr)
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit

	// The current implementation assumes there is no cache; so, every transaction is a miss
	return MISS;
}