//File: bigint.hpp
//Author: P.J. Leyden
//Desc: Contains class decleration for bigint

#ifndef CS2_BIGINT
#define CS2_BIGINT

#include <iostream>

const int CAPACITY = 200;

class bigint{
public:

	//constructors
	bigint();
	bigint(int);
	bigint(const char[]);


	void debugPrint(std::ostream&);
	bool operator==(const bigint&);

	friend std::ostream& operator<<(std::ostream&, bigint);

private:

	int size;
	int bigintArray[CAPACITY];

};

#endif