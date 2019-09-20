
class myclass{
public:
	myclass(int s){size = s; a=new int[size];}

	//operator assignment overload
	myclass& operator=(const myclass&);
	//myclass&       is the return type
	//operator=      is the name of the function
	//const myclass& is the type of the parameter passed

private:
	int size;
	int *a;
};

myclass& myclass::operator=(const myclass &org){
	//protection against self-assignment
	if(this == &org){
		return *this;
	}
	//copy size
	size = org.size;
	//delete old a if it exists
	if(a != nullptr){
		delete[] a;
	}
	//create new a of size "size"
	a = new int[size];
	//copy contents from org.a to a
	for(int i = 0; i < size; ++i){
		a[i] = org.a[i];
	}
	//allows stackabiliity by returing a dereferenced this
	return *this;
}

int main(){

	//mc1 is going to be a myclass object with an array of size 4.
	myclass mc1(4);

	//mc2 is going to be a myclass object with an array of size 7.
	myclass mc2(7);
	//leave mc1 and mc2 pointing to two DIFFERENT arrays of size 4 with 
	//the same contents
	mc2 = mc1;
	mc2.operator=(mc1);
	mc1.operator=(mc1);
	//the above two lines are equivalent.
	//"this" refers to mc2
	//  org  refers to mc1 

	//self assignemnt
	mc1 = mc1;



	myclass mc1(4);
	myclass mc2(56);
	myclass mc3(45);
	myclass mc4(7);

	mc4 = mc3 = mc1 = mc2;
}