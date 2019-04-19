#include "vararray.h"

varArray::varArray(){
	size = 0;
	dArray = new double[size];
}

int varArray::check(double number){
	//access to size is allowed because it is a private member
	for(int i = 0; i < size; ++i){
		//access to dArray for same reason
		//access to number because it is the parameter
		if(dArray[i] == number){
			return i;
		}
	}
	return -1;
}

void varArray::addNumber(double number){
	//we can call check without a varArray object
	//because we are in a method of the varArray class
	//and it is implied that we are calling it on this 
	if(check(number) != -1){
		return;
	}

	double *temp = new double[size + 1];
	for(int i = 0; i < size; ++i){
		temp[i] = dArray[i];
	}
	temp[size] = number;
	delete[] dArray;
	dArray = temp;
	++size;
}

void varArray::removeNumber(double number){
	if(check(number) == -1){
		return;
	}
	
	double *temp = new double[size - 1];
	bool found = false;
	for(int i = 0; i < size - 1; ++i){
		if(dArray[i] == number) found = true;
		if(found){
			temp[i] = dArray[i + 1];
		}else{
			temp[i] = dArray[i];
		}
	}

	delete[] dArray;
	dArray = temp;
	--size;
}

void varArray::output(){
	std::cout << "Your numbers are: ";
	for(int i = 0; i < size; ++i){
		std::cout << dArray[i] << " ";
	}
	std::cout << '\n';
}

varArray::varArray(const varArray &org){
	size = org.size;
	dArray = new double[size];
	for(int i = 0; i < size; ++i){
		dArray[i] = org.dArray[i];
	}
}

varArray& varArray::operator=(const varArray &org){
	if(this->dArray == org.dArray){
		return *this;
	}

	size = org.size;
	delete[] dArray;
	dArray = new double[size];
	for(int i = 0; i < size; ++i){
		dArray[i] = org.dArray[i];
	}

	return *this;
}

varArray::~varArray(){
	if(dArray != nullptr){
		delete[] dArray;
	}
}