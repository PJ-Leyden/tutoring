#include <iostream>
#include <string>

namespace mySpace{
	int x = 10;
	std::string food = "taco";
};
using namespace mySpace;
using namespace std;

int main(){

	//int x = 20;

	cout << "main x: " << x << '\n';
	std::cout << "mySpace x: " << x << '\n';

}