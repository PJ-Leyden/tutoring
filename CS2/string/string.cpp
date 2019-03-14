#include "string.hpp"

//default ctor 
String::String(){
	stringSize = 1;
	str = new char[stringSize];
	str[0] = 0;
}

//char ctor
String::String(char ch){
	stringSize = 2;
	str = new char[stringSize];
	str[0] = ch;
	str[1] = 0;
}

//char array ctor
String::String(const char arr[]){
	stringSize = 0;
	while(arr[stringSize] != 0){
		++stringSize;
	}

	//for the null character
	++stringSize;
	str = new char[stringSize];

	for(int i = 0; i < stringSize - 1; ++i){
		str[i] = arr[i];
	}
	str[stringSize - 1] = 0;
}

String::String(const String &org){
	stringSize = org.stringSize;
	str = new char[stringSize];
	for(int i = 0; i < stringSize - 1; ++i){
		str[i] = org.str[i];
	}

	str[stringSize - 1] = 0;
}

String::String(int size){
	stringSize = size;
	str = new char[stringSize];
	str[stringSize - 1] = 0;
}

String::String(int size, char org[]){
	assert(size > )
}

String::~String(){
	if(str != nullptr){
		delete[] str;
	}
}

std::ostream& operator<<(std::ostream &out, const String &rhs){
	for(int i = 0; i < rhs.stringSize - 1; ++i){
		out << rhs.str[i];
	}

	return out;
}

void String::resetCapacity(int size){
	//don't want to concatinate
	assert(size > capacity());
	char *tmp = new char[size];
	//make copy
}

String& String::operator+=(const String &rhs){

	*this = *this + rhs;
	return *this;
}

String String::operator+(const String &rhs){

	//int, char[] ctor, giving size of the lengths combined plus 1 for null terminator
	String result(length() + rhs.length() + 1, str);

	int offset = length();
	for(int i = 0; i < rhs.length(); ++i){
		result.str[offset + i] = rhs.str[i];
	}

	return result; 
}




