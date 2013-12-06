#pragma once
#include <string>
#include <iostream>
#include "cacheline.h"
using namespace std;

enum condition { MISS, HIT };
enum cacheType { DirectMapped, FullyAssociative };

class cacheSim
{
public:
	cacheSim(int cachelineSize, int cacheSize, int memorySize , bool isFullyAssociative );
	~cacheSim();
	int cachelineSize;				// The number of bytes per cache line
	int cacheSize;					// The overall cache size in bytes
	int memorySize;					// The overall memory (RAM) size in bytes
	int numberOfCachelines;
	cacheType cType;					
	unsigned int memGenSeq();
	unsigned int memGenRandom();
	unsigned int memGenLoop1();
	unsigned int memGenLoop2();
	condition cacheSimDM(unsigned int);
	condition cacheSimFA(unsigned int);
private:
	string condStr[2] = {"Miss","Hit"};
	string typestr[2] = { "Direct Mapped", "Fully Associative" };
	cacheline** cache;
};