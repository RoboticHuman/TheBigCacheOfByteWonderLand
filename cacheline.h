#pragma once

class cacheline
{
private:
	int size;
public:
	cacheline(int cachelineSize)
	{
		size = cachelineSize;
		valid = 0;
		tag = 0;
		counter = 0;
	}
	bool valid;
	int tag;
	int counter;
};