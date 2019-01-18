#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(){
	int guess;
	char ans;
	//Before game start
	do{
		srand(time(nullptr));
		int number = rand() % 200 + 1;
		do{//During Game

			std::cout << "Input a number between 1 - 200: ";
			std::cin >> guess;
			if(guess < number){
				std::cout << "Too Low!\n";
			}else if(guess == number){
				std::cout << "CORRECT!!!\n";
			}else if(guess > number){
				std::cout << "Too High!\n";
			}

		}while(guess != number);

		std::cout << "Do you want to play again? Y/N\n";
		std::cin >> ans;

	}while(ans != 'N');

	//After Game Finsh

}
