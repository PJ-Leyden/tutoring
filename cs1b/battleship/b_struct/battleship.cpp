#include "battleship.h"

void printShip(const Ship &s){
	cout << "Location: (" << s.loc.x << ", " << s.loc.y << ")\n";
	if(s.sunk){
		cout << "Sunk\n";
	}else{
		cout << "Afloat\n";
	}
}

void printFleet(const Ship fleet[]){
	for(int i = 0; i < fleetSize; ++i){
		printShip(fleet[i]);
	}
}

bool operational(const Ship fleet[]){
	for(int i =0; i < fleetSize; ++i){
		if(!fleet[i].sunk){
			return true;
		}
	}

	return false;
}

Location fire(){
	Location result;
	std::cout << "Enter coordinates: ";
	cin >> result.x >> result.y;
	std::cout << std::endl;
	return result;
}

void initialize(Ship fleet[]){
	for(int i = 0; i < fleetSize; i++){
		fleet[i].loc.x = -1;
		fleet[i].loc.y = '*';
	}
}

Location pick(){
	Location result;

	result.x = rand()%6; 0-5
	result.y = (char)(rand()%6 + 97); a-f
	//code

	return result;
}

bool match(const Ship &s, const Location &l){
	if(l.x == s.loc.x && l.y == s.loc.y){
		return true;
	}
	return false;
}

int check(const Ship fleet[], const Location &l){
	for(int i = 0; i < fleetSize; ++i){
		if(match(fleet[i], l)){
			return i;
		}
	}
	return -1;
}

void deploy(Ship fleet[]){
	
	int ships_deployed = 0;

	while(ships_deployed < fleetSize){
		Location tmp = pick();
		int indx = check(fleet, tmp);
		if(indx == -1){
			fleet[ships_deployed].loc.x = tmp.x;
			fleet[ships_deployed].loc.y = tmp.y;
			++ships_deployed;
		}
	}
}

void sink(Ship &s){
	s.sunk = true;
}