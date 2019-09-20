#include <iostream>
#include <ctime>
#include <cstdlib>



int find_max(int a[][100], int size){

	int max = a[0][0];
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			if(a[i][j] > max){
				max = a[i][j];
			}
		}
	}

	return max;
}


int main(){
	srand(time(nullptr));
	
	const int SIZE = 100;
	int a[SIZE][SIZE];

	for(int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE; ++j){
			a[i][j] = (rand()%1000000 + 1);
		}
	}

	int m = find_max(a, SIZE);

	std::cout << m << '\n';

	return 0;
};