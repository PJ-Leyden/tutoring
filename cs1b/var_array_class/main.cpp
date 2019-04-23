#include "vararray.h"

int main(){

	varArray myArray;	

	myArray.addNumber(12.3);
	myArray.addNumber(234.78);
	myArray.addNumber(1.2);
	myArray.output();

	//remove number
	myArray.removeNumber(12.3);
	myArray.output();

	//remove number that's not there
	myArray.removeNumber(8.9);
	myArray.output();

	//add number already in array
	myArray.addNumber(1.2);
	myArray.output();

	return 0;

}