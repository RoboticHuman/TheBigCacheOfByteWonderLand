#pragma once
#include <string>
#include <iostream>
#include "cacheline.h"
#include <map>
#include <fstream>
using namespace std;


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//\\	   ____                     __                __                       
//\\	  /\  _`\                  /\ \              /\ \_   __                
//\\	  \ \ \/\_\     __      ___\ \ \___      __  \/'__`\/\_\    ___ ___    
//\\	   \ \ \/_/_  /'__`\   /'___\ \  _ `\  /'__`\/\ \_\_\/\ \ /' __` __`\  
//\\	    \ \ \L\ \/\ \L\.\_/\ \__/\ \ \ \ \/\  __/\ \____ \ \ \/\ \/\ \/\ \ 
//\\	     \ \____/\ \__/.\_\ \____\\ \_\ \_\ \____\\/\ \_\ \ \_\ \_\ \_\ \_\
//\\	      \/___/  \/__/\/_/\/____/ \/_/\/_/\/____/ \ `\_ _/\/_/\/_/\/_/\/_/
//\\	                                                `\_/\_\					BETA
//\\	                                                   \/_/                
//\\	                                                                       
//\\	
//\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//\\	1 - Install the font attached(for a better experience)
//\\	2 - If you want to try it run the file CacheSimulator.exe
//\\	3 - For the source code you'll find 42 attached files that include the simulator and the graphical user interface code.
//\\
//\\
//\\	The files for the base simulator are :
//\\	cacheSim.cpp
//\\	cacheSim.h
//\\	cacheline.h
//\\
//\\	The remaining files are for the Qt interface.
//\\
//\\	Github repository link : https ://github.com/RoboticHuman/TheBigCacheOfByteWonderLand.git
//\\
//\\
//\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//\\	This program has been made for the course CSCE 231 under the supervision of Dr.Mohamed Shalan
//\\
//\\	Ibrahim ElSebaie - 900120478
//\\	Omar ElBehady - 900121388
//\\	Hassan ElTahan - 900101697
//\\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\


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
    map<int,int>arrayIndex;
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
