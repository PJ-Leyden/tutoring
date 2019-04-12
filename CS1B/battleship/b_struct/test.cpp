int String::findstr(int start, const String &s) const{

	if(s.length > length() - start){
		return -1;
	}

	for(int i = start; i < length() - s.length(); ++i){
		String tmp = substr(i, i + s.length());
		if(tmp == s){
			return i;
		}
	}

	return -1;

}





class Boat{

	string name;
	int cap;
	string owner;

public:
	Boat(){};
	//Boat(int x){cap = x;}
	Boat(int x) : cap(x) {} 
}

int main(){

Boat b1;
Boat b2(10);

}




















