#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){

	vector<string> myVector;

	myVector.push_back("Hello");
	myVector.push_back("World");
	myVector.push_back("Taco Bell");

	cout << "Front: " <<    myVector.front()   << '\n';
	cout << "Begin: " << *( myVector.begin() ) << '\n';
	cout << "Back: " << myVector.back() << '\n';

	vector<string>::iterator itr = myVector.begin();

	return 0;
}