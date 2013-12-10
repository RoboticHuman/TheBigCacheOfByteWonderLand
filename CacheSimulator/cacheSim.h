#pragma once
#include <string>
#include <iostream>
#include "cacheline.h"
#include <map>
#include <fstream>
using namespace std;

enum condition { MISS, HIT };
enum cacheType { DirectMapped, FullyAssociative };
enum replacementMethod { RANDOM , FIFO, LFU };
class cacheSim
{
public:
	cacheSim(int cachelineSize, int cacheSize, int memorySize , bool isFullyAssociative , int repmethod );
	~cacheSim();
    void run(int inst);
	double getHitRatio();
    int Hits[4];
    double Ratio[4];
	int getHits();
	int getMisses();
    ofstream out;
    string condStr[2] ;
    string typestr[2] ;
    cacheline** cache;
    int cachelineSize;				// The number of bytes per cache line
    int cacheSize;					// The overall cache size in bytes
    int memorySize;					// The overall memory (RAM) size in bytes
    int numberOfCachelines;			// Number of cache lines
private:

	int hitCounter;					// Counts the total number of hits
	int missCounter;				// Counts the total number of misses
	double hitRatio;				// The total number of hits per instruction 

	bool bFull;						// Used by the FA cache to determine whether the cache has already been completely filled
	cacheType cType;				// DirectMapped or FullyAssociative
	replacementMethod repMethod;
	unsigned int memGenSeq();
	unsigned int memGenRandom();
	unsigned int memGenLoop1();
	unsigned int memGenLoop2();

	condition cacheSimDM(unsigned int);
	condition cacheSimFA(unsigned int);

	void clearCache();

	int log2(int);
	int replace();
	condition(cacheSim::*simulateCache[2])(unsigned int);		// Array of pointers to functions
	unsigned int (cacheSim::*memGen[4])();
};
