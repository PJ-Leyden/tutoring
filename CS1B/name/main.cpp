#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct names{
	string firstname;
	string lastname
	char gender;
	int age;
}

void reading_file_input(ifstream data, names *lines){
	string num_lines;
	getline(data, num_lines);
	int num = num_lines[0] - 48;

	lines = new names[num];
	for(int i = 0; i < num; ++i){
		string temp;
		getline(data, temp);
		int mark = 0;
		for(int j = 0; j < temp.size(); ++j){
			if(temp[j] == ' '){
				names[i].firstname = temp.substr(mark, j - mark - 1);
				mark = j;
			}
		}

		for(int j = mark; j < temp.size(); ++j){
			if(temp[j] == ' '){
				names[i].lastname = temp.substr(mark, j - mark - 1);
				mark = j;
			}
		}


	}
}

int determine_gender_totals(){

}

int main(){

	ifstream data1("data1.txt");
	ifstream data2("data2.txt");

	names *data1info;
	reading_file_input(data1, data1info);
	data1.close();

	names *data2info;
	reading_file_input(data2, data2info);
	data2.close();

	ofstream data1("data1.txt");
	ofstream data2("data2.txt");

	for(int i = 0; i < data1Lines.size(); ++i){

	}


}