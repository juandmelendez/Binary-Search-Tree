#pragma once
#include <iostream>
using namespace std;

template <class T>
class IntSLLNode {

public:
	IntSLLNode(); //Default Constructor
	IntSLLNode(T, IntSLLNode <T>*); //Special Constructor
	T getInfo(); //getInfo
	IntSLLNode<T>* getNext(); //getNext
	void setInfo(T); //setInfo
	void setNext(IntSLLNode<T>*); //setNext

private:
	T info; //Actual Data
	IntSLLNode<T>* next; //Points to the next node on the list
};

template <class T>
IntSLLNode<T>::IntSLLNode() {
	next = 0;
}

template <class T>
IntSLLNode<T>::IntSLLNode(T i, IntSLLNode <T> * n) {
	info = i;
	next = n;
}

template <class T>
T IntSLLNode<T>::getInfo() {
	return info;
}

template <class T>
IntSLLNode<T>* IntSLLNode<T>::getNext() {
	return next;
}

//setInfo: set i as the node info
template <class T>
void IntSLLNode<T>::setInfo(T i) {
	info = i
}

//setNext: points next attribute to the next list node
template <class T>
void IntSLLNode<T>::setNext(IntSLLNode<T>* n) {
	next = n
}