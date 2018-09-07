#include <iostream>
#include <fstream>
#include <string>

struct StudentInfo {
	char name[21];
	char junk[12];
	char num[11];
	char call[6];
	char test[3];
	char special[4];
	char score[4];
	char answers[106];
};

int main() {
	std::ifstream scanner;
	scanner.open("testfile.txt");
	std::ofstream printer;
	printer.open("testfile2.txt");

	while (!scanner.eof()) {
		std::string curline;
		std::getline(scanner, curline);
		StudentInfo si;

		if(curline.length() != 0){
			std::size_t len = curline.copy(si.name, 20, 0);
			si.name[len] = '\0';

			len = curline.copy(si.junk, 11, 20);
			si.junk[len] = '\0';
		
			len = curline.copy(si.num, 10, 31);
			si.num[len] = '\0';
		
			len = curline.copy(si.call, 5, 41);
			si.call[len] = '\0';
		
			len = curline.copy(si.test, 2, 46);
			si.test[len] = '\0';
		
			len = curline.copy(si.special, 3, 48);
			si.special[len] = '\0';
		
			len = curline.copy(si.score, 3, 51);
			si.score[len] = '\0';
		
			len = curline.copy(si.answers, 105, 54);
			si.answers[len] = '\0';

			printer << si.name << si.num << si.call << si.test << si.special << si.score << si.answers << std::endl;
		}
	}
	scanner.close();
	printer.close();
}