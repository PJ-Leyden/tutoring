#include <iostream>

void recurse(int x){
	if(x < 10){
		std::cout << "Recursing x: " << x << "\n";
		recurse(x+1);
	}else{
		std::cout << "Leaving\n";
	}
}

int main(){
	int x = -100;

	
	std::cout << "Recursion\n";
	std::cout << "======================================\n";
	recurse(x);
	std::cout << "======================================\n";



	std::cout << "Iteration\n";
	std::cout << "======================================\n";
	for(int i = x; i < 10; ++i){
		std::cout << "Iterating i: " << i << '\n'; 
	}
	std::cout << "Leaving\n";
	std::cout << "======================================\n";

	return 0;
}