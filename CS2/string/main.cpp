#include <string>
#include "string.hpp"

int main(){

	String s1("Hello");

	String s2(s1);

	std::cout << "String s1: " << s1 << std::endl;

	std::cout << "String s2: " << s2 << std::endl;

}