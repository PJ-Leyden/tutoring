
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    3/2019
//
//
//
//

#include <new>

////////////////////////////////////////////////////////////////////////////
//           
template <typename T> 
class Node {
public:
	Node<T>(){next = nullptr;}
	Node<T>(T d): data(d){next = nullptr;}

	//data of current node
	T data;
	//pointer to next node in stack;
	Node<T> *next;
	//Node<T> *prev;
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
              stack     ();
              //stack     (stack<T>&);
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};

//IMPLEMENTATION

template <typename T>
stack<T>::stack(){
	tos = nullptr;
}

//deep copy constructor
template <typename T>
stack<T>::stack(const stack<T> &org){
	//empty copy
	if(org.tos == nullptr){
		tos = nullptr;
		return;
	}

	Node<T> *ptr = org.tos;
	Node<T> *ptr2 = tos;

	tos = new Node<T>(ptr->data);
	ptr = ptr->next;

	while(ptr != nullptr){
		ptr2->next = new Node<T>(ptr->data);
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}
}

template <typename T>
void stack<T>::push(const T &x){
	Node<T> *temp = new Node<T>(x);
	temp->next = tos;
	tos = temp;
}

template <typename T>
T stack<T>::pop(){
	
}
//shallow copy
//stack::stack(stack<T> &org){}



#endif

