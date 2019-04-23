#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::string; using std::cout; using std::cin;
using std::ofstream; using std::ifstream; using std::getline;
using std::endl;

const int lineWidth = 75;

//add a space after each punc
void punc(string &s){

	int pos = s.find_first_of(".,?!;'", 0);
	while(pos != string::npos && s.length() < 75){
		s.insert(pos + 1, " ");
		pos = s.find_first_of(".,?!;'", pos + 1);
	}

}

//add spaces at random until length is 75
void spaces(string &s){
	/*


    */
}

int main(){

	srand(time(nullptr));

	ifstream inFile("unjustified.txt");
	ofstream outFile("justified.txt");

	string line;
	getline(inFile, line);

	while(!inFile.eof()){
		punc(line);
		if(line.length() < lineWidth){
			spaces(line);
		}

		outFile << line << endl;
		getline(inFile, line);
	}	

	return 0;
}