//Name: P.J. Leyden
//File: LabStack.cpp
//Date: March 29th, 2016

#include <iostream>

template <typename T>
class node{
public:
	T data;
	node<T>* next;

	node():next(0){};
	node(const T& x):data(x), next(0){};
};
//=========================================
template <typename T>
class Stack{
public:
	          Stack():tos(0){};//init a default Stack with top of stack(tos) pointing at 0
	          Stack(Stack<T>&& rhs):Stack(){swap(rhs);};
	          Stack(const Stack<T>&);
	          ~Stack();//deconstructor
	void      swap(Stack<T>&);
	Stack<T>& operator=(Stack<T>);
	bool      isEmpty()const{return tos == 0;};//returns true if tos points to zero, meaning empty
	bool      isFull()const;//returns true if full
	T         pop();
	void      push(const T& newData);
private:
	node<T>* tos;
};
//=========================================


template <typename T>
Stack<T>::Stack(const Stack<T> &org){
	//check for the org being null
	if(org.tos == nullptr){
		tos == nullptr;
		return;
	}

	//creating initial node
	tos = new node(org.tos->data);
	//we create two node ptr that we will move down the stack
	node<T> *cur = tos, *org_ptr = org.tos;
	//we move the first ppointer down
	org_ptr = org_ptr->next;
	
	//so while we havne't bottomed out the original stack
	while(org_ptr != nullptr){
		//make a copy of the node
		cur->next = new node<T>(org_ptr->data);
		//move the org_ptr down one
		org_ptr = org_ptr->next;
		//move the cur down one 
		cur = cur->next;
	}
}