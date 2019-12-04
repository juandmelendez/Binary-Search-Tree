#pragma once

template <class T>
class IntDLLNode {

public:
	IntDLLNode();
	IntDLLNode(IntDLLNode<T>*, T, IntDLLNode<T>*);
	T getInfo();
	IntDLLNode<T>* getNext();
	IntDLLNode<T>* getPrev();
	void setInfo(T);
	void setNext(IntDLLNode<T>*);
	void setPrev(IntDLLNode<T>*);

private:
	IntDLLNode<T>* prev;
	T info;
	IntDLLNode<T>* next;
};

//
template <class T>
IntDLLNode<T>::IntDLLNode() {
	next = prev = 0;
}

template <class T>
IntDLLNode<T>::IntDLLNode(IntDLLNode<T>* p, T i, IntDLLNode<T>* n) {
	prev = p;
	info = i;
	next = n;
}

template <class T>
T IntDLLNode<T>::getInfo() {
	return info;
}

template <class T>
IntDLLNode<T>* IntDLLNode<T>::getNext() {
	return next;
}

template <class T>
IntDLLNode<T>* IntDLLNode<T>::getPrev() {
	return prev;
}

template <class T>
void IntDLLNode<T>::setInfo(T i) {
	info = i;
}

template <class T>
void IntDLLNode<T>::setNext(IntDLLNode<T>* n) {
	next = n;
}

template <class T>
void IntDLLNode<T>::setPrev(IntDLLNode<T>* p) {
	prev = p;
}