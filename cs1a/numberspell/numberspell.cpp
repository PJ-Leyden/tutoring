#include <iostream>
#include <string>

using namespace std;

int main(){

//1 - 50

int number;
cout << "Input a number (1-50): ";
cin >> number; //46

int tens = number / 10;//4
int singles = number % 10;//6

//0 - 9
//10 - 19
//20 - 50
if(number > 9 && number < 20){
	switch(number){
		case 10:
			cout << "Ten" << endl;
			break;
		case 11:
			cout << "Eleven" << endl;
			break;
			//
			//filled

	}
}else{

	switch(tens){
		case 0:
			break;
		case 2:
			cout << "Twenty ";
			break;
		case 3:
			cout << "Thirty ";
			break;
		case 4:
			cout << "Forty ";
			break;
		case 5:
			cout << "Fifty ";
			break;
	}

	switch(singles){
		//filled
	}
	
}



}