class Fruit{
public:
	virtual ~Fruit(){};
	void buy();
	virtual void weigh(){ //default weigh 
						};
	virtual void eat() = 0;

private:
	std::string name;
	double price;
};

class Apple : public Fruit{
public:
	void weigh();
	void eat();
}

class Banana : public Fruit{
public:
	void eat();
}