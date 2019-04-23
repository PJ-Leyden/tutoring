#include <iostream>
#include <fstream>
#include <string>

struct Organizer {
	std::string * arr = NULL;
	int numM = 0;
	int numF = 0;
	int total = 0;
};

int main() {

	//open our data files
	std::ifstream data1;
	data1.open("datafile1.txt");

	std::ifstream data2;
	data2.open("datafile2.txt");
	//==========================

	Organizer o1;
	int numd1;
	int numd2;

	int numFperFile = 0;
	int numMperFile = 0;

	std::string firstLine;
	std::getline(data1, firstLine);
	o1.total = firstLine[0] - 48;
	numd1 = o1.total;

	std::getline(data2, firstLine);
	o1.total += firstLine[0] - 48;
	numd2 = firstLine[0] - 48;
	//===========================
	o1.arr = new std::string[o1.total];
	//=========================== Datafile1
	for(int i = 0; i < numd1; i++){
		std::string curLine;
		std::getline(data1, curLine);
		if(curLine[curLine.size() - 1] == 'M'){
			o1.numM++;
			numMperFile++;
		}else if(curLine[curLine.size() - 1] == 'F'){
			o1.numF++;
			numFperFile++;
		}
		o1.arr[i] = curLine;
	}
	//===========================
	std::cout << "datafile1.txt contained " << numFperFile << " female names and " << numMperFile << " male names." << std::endl;
	numFperFile = 0;
	numMperFile = 0;
	//=========================== Datafile2
	for(int i = 0; i < numd2; i++){
		std::string curLine;
		std::getline(data2, curLine);
		if(curLine[curLine.size() - 1] == 'M'){
			o1.numM++;
			numMperFile++;
		}else if(curLine[curLine.size() - 1] == 'F'){
			o1.numF++;
			numFperFile++;
		}
		o1.arr[i + numd1] = curLine;
	}

	std::cout << "datafile2.txt contained " << numFperFile << " female names and " << numMperFile << " male names." << std::endl;

	data1.close();
	data2.close();

	/*for(int i = 0; i < o1.total; i++){
		std::cout << o1.arr[i] << std::endl;
	}*/

	std::ofstream data3;//female
	data3.open("data1.txt");
	std::ofstream data4;//male
	data4.open("data2.txt");

	data3 << o1.numF << " female" << std::endl;
	data4 << o1.numM << " male" << std::endl;

	for(int i = 0; i < o1.total; i++){
		if(o1.arr[i][o1.arr[i].size() - 1] == 'F'){
			data3 << o1.arr[i] << std::endl;
		}else if(o1.arr[i][o1.arr[i].size() - 1] == 'M'){
			data4 << o1.arr[i] << std::endl;
		}
	}
}