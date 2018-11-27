//File: test.cpp
//Author: P.J. Leyden
#include <cmath>
#include <iostream>

using namespace std;

int main(){
	string str = "the end of the world the the the taco  bell";
	string find = "the";

	int instances = 0;
	int pos;
	int start = 0;

	do{
		pos = str.find(find, start);

		if(pos != string::npos){
			instances++;
		}

		start = pos + find.length();

	}while(pos != string::npos && start < str.length());

	cout << "Instances: " << instances << endl;

	return 0;
}