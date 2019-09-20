int main(){
	//define a pointer p, an array a and an int i
	int *p, a[10], i=5;

	// due to the line below p -> i
	p = &i;

	++(*p);
	a[0] = *p;
	p = a;
	cout << p[0];

}