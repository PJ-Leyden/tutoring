#include <iostream>
#include <string>
#include <vector>

using std::vector;

int main(){

	int a[3][3];

	vector< vector<int> > v2;

	for(int i = 0; i < 3; ++i){

		vector<int> temp;

		for(int j = 0; j < 3; ++j){

			temp.push_back(a[i][j]);
			//a[0][0]
			//a[0][1]
			//a[0][2]

		}

		v2.push_back(temp);

	}

	//v2 and a should be essentially equivalent


}