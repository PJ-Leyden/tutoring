#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){

	/*for(int i = 0; i < argc; ++i){
		std::cout << argv[i] << std::endl;
		}
	*/

	std::ifstream input_file("i_file.txt");
	std::ofstream output_file("o_file.txt");
/*
	int count = 0;

	while(!input_file.eof()){
		std::string cur_line;
		std::getline(input_file, cur_line);
		++count;
		std::cout << cur_line << std::endl;
		output_file << cur_line << std::endl;
	}

	std::cout << "Number of lines: " << count << std::endl;
*/
	while(!input_file.eof()){

		//get a line
		//read through line and parse out
		//name, id, class, section, score, and answers
		//==========================================================================
		//Leyden PJ              810810999 15231 002 9812342311234211234223322123232

		std::string cur_line;
		std::string name;
		bool foundName = false;


		std::getline(input_file, cur_line);
	

		for(int indx = 0; indx < cur_line.length(); ++indx){
			if(cur_line[indx] == ' ' && cur_line[indx + 1] == ' ' && !foundName){
				name = cur_line.substr(0, indx);
				std::cerr << "X" << name << "X\n";
				foundName = true;
			}
		}
	}
	

	input_file.close();
	output_file.close();

	return 0;

}