#include "bigint.hpp"

bigint::bigint(){
	for(int i =0; i < CAPACITY; ++i){
		bigintArray[i] = 0;
	}

	size = 1; // or size = 0;
}

bigint::bigint(int num){
	int pos = 0;
	while(num > 0){
		bigintArray[pos] = num % 10;
		num = num / 10;
		++pos;
	}
}

bigint::bigint(const char num[]){


}

void bigint::debugPrint(std::ostream& out){


}

bool bigint::operator==(const bigint& rhs){


}

std::ostream& operator<<(std::ostream& out, bigint num){

	
}