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
	cache = new cacheline*[numberOfCachelines];
	for (int i = 0; i < numberOfCachelines; i++)
		cache[i]=new cacheline(cachelineSize);
	// to acceess cache location of i we have to say *(cache[i])
	hitCounter = 0;

	simulateCache[0] = cacheSimDM;
	simulateCache[1] = cacheSimFA;
	memGen[0] = memGenSeq;
	memGen[1] = memGenRandom;
	memGen[2] = memGenLoop1;
	memGen[3] = memGenLoop2;
	for (int inst = 0 ; inst< 400000 ; inst++)
	{
		unsigned int addr = (this->*this->memGen[inst / 4])();
		condition r = (this->*this->simulateCache[cType])(addr);
		hitCounter += r;
	//	cout << addr << " (" << condStr[r] << ")\n";
	}
	hitRatio = double(hitCounter) / 400000.0;
}

cacheSim::~cacheSim()
{
	for (int i = 0; i < numberOfCachelines; i++)
		delete cache[i];
	delete[]cache;
}

unsigned int cacheSim::memGenSeq()
{
	static unsigned int addr = 0;
	return (addr++) % (memorySize);
}

unsigned int cacheSim::memGenRandom()
{
	return rand() % (memorySize);
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

double cacheSim::getHitRatio()
{
	return hitRatio;
}