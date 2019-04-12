#include "varArray.h"

void addNumber(double *& arrayPtr, double number, int &size){
	if(check(arrayPtr, number, size) == -1){
		
		double *temp = new double[size + 1];
		for(int i = 0; i < size; ++i){
			temp[i] = arrayPtr[i];
		}
		temp[size] = number;
		delete[] arrayPtr;
		arrayPtr = temp;
		++size;

	}
}