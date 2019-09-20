#include <vector>
#include <iostream>

int main(){
	std::vector<int> v;
	std::cout << "Size: " << v.size() << '\n';
	std::cout << "Cap: " << v.capacity() << '\n';

	for(int i = 0; i < 100; ++i){
		v.push_back(i);
		std::cout << "Size: " << v.size() << '\n';
		std::cout << "Cap: " << v.capacity() << '\n';
	}

	return 0;


}