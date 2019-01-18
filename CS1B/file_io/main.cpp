#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){

	/*for(int i = 0; i < argc; ++i){
		std::cout << argv[i] << std::endl;
		}
	*/

	std::ifstream input_file(argv[1]);
	std::ofstream output_file("o_file.txt");

	int count = 0;

	while(!input_file.eof()){
		std::string cur_line;
		std::getline(input_file, cur_line);
		++count;
		std::cout << cur_line << std::endl;
		output_file << cur_line << std::endl;
	}

	std::cout << "Number of lines: " << count << std::endl;

	while(!input_file.eof()){

		//get a line
		//read through line and parse out
		//name, id, class, section, score, and answers
		//==========================================================================
		//Leyden PJ              810810999 15231 002 9812342311234211234223322123232

		std::string cur_line;
		std::getline(input_file, cur_line);
		int spaces = 0;
		std::string name;
		for(int indx = 0; indx < cur_line.length(); ++indx){
			if(cur_line[indx] == ' '){
					++spaces;
				if(spaces == 2){
					name = cur_line.substr(0, indx);
					//std::cerr << "X" << name << "X\n";
				}
			}
		}
	}
	

	input_file.close();
	output_file.close();

	return 0;

}