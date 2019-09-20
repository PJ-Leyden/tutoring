#include <iostream>
#include <string>

int main(){

	const int oceanwidth = 6;
	const int oceanheight = 6;
	char answer;
	bool shots[oceanwidth][oceanheight];
	for(int i = 0; i < oceanwidth; ++i){
		for(int j = 0; j < oceanheight; ++j){
			shots[i][j] = false;
		}
	}

	do{
		std::cout << "Another shot? [y/n] ";
		std::cin >> answer;
		if(answer == 'y' || answer == 'Y'){
			std::cout << "Location? ";
			char x;
			int y;
			std::cin >> x;
			std::cin >> y;
			shots[y-1][(int)x - 97] = true;
			std::cout << " a b c d e f \n";
			for(int i = 0; i < oceanwidth; ++i){
				std::cout << i+1;
				for(int j = 0; j < oceanheight; ++j){
					if(shots[i][j]){
						std::cout << "* ";
					}else{
						std::cout << "  ";
					}
				}
				std::cout << '\n';
			}
		}

	}while(answer != 'n' && answer != 'N');

	return 0;
}