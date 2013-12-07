#include <iostream>
#include <cmath>
#include <ctime>
#include "cacheSim.h"

using namespace std;

int nextlocation = 0;

cacheSim::cacheSim(int cachelineSize, int cacheSize, int memorySize, bool isFullyAssociative, int repmethod)
{
	srand(time(0));
	condStr[0] = "Miss";
	condStr[1] = "Hit";
	typestr[0] = "Direct Mapped";
	typestr[1] =  "Fully Associative";
	repMethod = replacementMethod(repmethod);
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
	bFull = 0;

	simulateCache[0] = &cacheSim::cacheSimDM;
	simulateCache[1] = &cacheSim::cacheSimFA;
	memGen[0] = &cacheSim::memGenSeq;
	memGen[1] = &cacheSim::memGenRandom;
	memGen[2] = &cacheSim::memGenLoop1;
	memGen[3] = &cacheSim::memGenLoop2;

    run();
}

void cacheSim::run()
{
    for(int inst=0 ; inst<400000 ; inst++)
    {
        if (inst % 100000 == 0)
            clearCache();
        unsigned int addr = (this->*this->memGen[inst / 100000])();
        condition r = (this->*this->simulateCache[cType])(addr);
        hitCounter += r;
        missCounter += (1 - r);
        //cout << "0x" << hex << addr << " (" << condStr[r] << ")\n";
        hitRatio = double(hitCounter) / 400000.0;
    }
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
	unsigned int tag, index, offset;
	int bitsTotal = log2(memorySize);
	int bitsOffset = log2(cachelineSize);
	int bitsIndex = log2(numberOfCachelines);
	int bitsTag = bitsTotal - (bitsOffset + bitsIndex);

	addr = addr >> bitsOffset;												 // getting rid of the bits of the offset
	index = addr << (32 - bitsIndex); 	index = index >> (32 - bitsIndex);	 // Extracting the index
	tag = addr >> bitsIndex;												 // Extracting the tag
	if (cache[index]->valid && tag == cache[index]->tag)
		return HIT;
	cache[index]->valid = 1;
	cache[index]->tag = tag;
	return MISS;
}

// Fully Associative Cache Simulator
condition cacheSim::cacheSimFA(unsigned int addr)
{
    unsigned int tag, offset;
	int bitsTotal = log2(memorySize);
	int bitsOffset = log2(cachelineSize);
	int bitsTag = bitsTotal - bitsOffset;
	tag = addr >> bitsOffset;

	for (int i = 0; i < numberOfCachelines; i++)
	{
		if (cache[i]->valid && tag == cache[i]->tag)
		{
			cache[i]->counter++;
			return HIT;
		}
	}
	cache[nextlocation]->valid = 1;
	cache[nextlocation]->tag = tag;
	cache[nextlocation++]->counter = 1;
	if (nextlocation == numberOfCachelines)
		bFull = true;
	if (bFull)
		nextlocation = replace();
	return MISS;
}

int cacheSim::replace()
{
	switch (repMethod)
	{
	case RANDOM:
		return rand() % numberOfCachelines;
	case FIFO:
		bFull = 0;
		return 0;
	case LFU:
		int minimum = INT_MAX;
		int minIndex = 0;
		for (int i = 0; i < numberOfCachelines; i++)
			if (cache[i]->counter < minimum)
			{
				minimum = cache[i]->counter;
				minIndex = i;
			}
		return minIndex;
	}
    return 0;
}

double cacheSim::getHitRatio()
{
	return hitRatio;
}

int cacheSim::getHits()
{
	return hitCounter;
}

int cacheSim::getMisses()
{
	return missCounter;
}

void cacheSim::clearCache()
{
    for (int i = 0; i < numberOfCachelines; i++)
    {
        cache[i]->valid = 0;
    }
    bFull = false;
    nextlocation = 0;
}

int cacheSim::log2(int x)
{
	return ( int(log10(double(x))/log10(2.0)) );
}
