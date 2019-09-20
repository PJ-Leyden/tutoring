#include <iostream>
#include <vector>

void print(std::vector<int> &v){
	std::cout << "===================================\n";
	for(int i = 0; i < v.size(); ++i){
		std::cout << "v at " << i << ": " << v[i] << '\n';
	}
	//std::cout << std::endl;
	std::cout << "===================================\n";
}


int main(){
	//c++ has a standard library and std::vector is a class
	//whereas a "raw" array is a primative construct

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//my vector v currenetly has
	//Contents: [10, 20, 30, 40, 50] [HERE]
	//Indicies:   0,  1,  2,  3,  4

	print(v);

	std::vector<int>::iterator v_itr;
	v_itr = v.begin();
	
	//now v_itr is pointing at 10;
	//std::cout << *v_itr << '\n';

	//v_itr = v.end();

	//v_itr points to just BEYOND the last index
	//std::cout << *v_itr << '\n';
	

	v_itr = v.begin() + 2;	

	//v_itr += 2;

	v.insert(v_itr, 33);
	//[10, 20, 33, 30, 40, 50]
	std::cout << "After Insert\n";
	print(v);

	v.erase(v_itr + 1);

	std::cout << "After Erase\n";
	print(v);

	return 0;
}