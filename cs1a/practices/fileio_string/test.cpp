//File: test.cpp
//Author: P.J. Leyden
//Date: October 5th, 2019

/*
Notes:

Good string reference site
	http://www.cplusplus.com/reference/string/string/

Good input file stream reference (ifstream)
	http://www.cplusplus.com/reference/fstream/ifstream/

Good outout file stream reference (ofstream)
	http://www.cplusplus.com/reference/fstream/ofstream/

Nesterenko's examples: 
	http://vega.cs.kent.edu/~mikhail/classes/csi/Examples/Io/
*/

#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::cout; using std::cin; using std::endl;

int main(){

	//create and print a string
	string mystring = "Hello World!";
	cout << mystring << endl;

	//read a string
	string input;
	cin >> input;
	cout << "Input: " << input << endl;

	//open file for reading
	std::ifstream ifile("mydata.txt");

	//read a single word
	string file_word;
	ifile >> file_word;
	cout << file_word << endl;

	//read a full line
	string line;
	std::getline(ifile, line);
	cout << line << endl;

	//read a full file
	while(!ifile.eof()){
		std::getline(ifile, line);
		cout << line << endl;
	}

	//notice that the file never starts over if you want to go back to the beginning of the file you'd have to close it
	//and reopen it. 

	//open file for writing
	std::ofstream ofile("mynewfile.txt");
	ofile << "The new file has this in it." << endl;

	return 0;
}