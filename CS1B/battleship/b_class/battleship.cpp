#include "battleship.h"

//Location=====================

Location::Location(){
	x = -1;
	y = '*';
}

void Location::pick(){
	x = rand() % 6 + 1;
	y = (char)(rand()%6 + 97);
}

void Location::fire(){
	std::cout << "Enter x (1-6): ";
	cin >> x;
	std:;cout << "\nEnter y (a-f): ";
	cin >> y;
	std::cout << '\n';
}

void Location::print(){
	std::cout << y << x << std::endl;
}

bool compare(const Location &l1, const Location &l2){
	return (l1.x == l2.x && l1.y == l2.y);
}


//Ship========================

Ship::Ship(){
	sunk = false;
}

bool Ship::match(const Location &l) const{
	if(compare(loc, l)){
		return true;
	}else{
		return false;
	}
}

void Ship::sink(){
	sunk = true;
}

void Ship::setLocation(const Location &l){
	loc = l;
}

void Ship::printShip() const{
	loc.print():
	if(sunk){
		std::cout << "Sunk!\n";
	}else{
		std::cout << "Afloat!\n";
	}
}

//Fleet=======================

bool Fleet::isHitNSink(const Location &l){
	for(int i = 0; i < fleetSize; ++i){
		if(ships[i].match(l)){
			ships[i].sink();
			return true;
		}
	}
	return false;
}

int main(){

	const Ship myship;
	//loc   -1 *
	//sunk  false


	myship.printShip();

}