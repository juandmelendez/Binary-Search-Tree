#pragma once
#include "IntSLLNode.h"

template <class T>
class IntSLList {

public:
	IntSLList(); //Default Constructor
	~IntSLList(); //Destructor
	void addToHead(T val);
	void addToTail(T val);
	void deleteFromHead(); 
	void deleteFromTail();
	bool isEmpty();
	void sortInsert(T val);
	void printList();
	void deleteButHead();
	void deleteButTail();
	void addIn(int pos, int val);

private:
	IntSLLNode<T>* head; //Pointer to first node
	IntSLLNode<T>* tail; //Pointer to last node
};

//Creates an empty list. Head and tail point to null.
template <class T>
IntSLList<T>::IntSLList() {
	tail = head = 0;
}

//Deallocate memory by removing each node from the list.
template <class T>
IntSLList<T>::~IntSLList() {
	IntSLLNode<T>* ptrNode;
	ptrNode = head; //ptrNode points to head

	while (ptrNode != 0) { //While there is a node in the list, remove it
		ptrNode = head->getNext(); //ptrNode points to the node after the head
		delete head; //Delete head
		head = ptrNode; //New head is ptrNode
	}
}

//Creates a new node with val as info, new node is the new head.
template <class T>
void IntSLList<T>::addToHead(T val) {
	head = new IntSLLNode<T>(val, 0);
	if (tail == 0) {
		tail = head;
	}
}

//Creates a new node with val as info, new node it the new tail.
template <class T>
void IntSLList<T>::addToTail(T val) {
	if (tail != 0) {
		tail->setNext(new IntSLLNode <T>(val, 0));
		tail = tail->getNext();
	}
	else {
		head = tail = new IntSLLNode <T>(val, 0);
	}
}

//Removes head from the list. New head is head->getNext(). If the list had only one node, head and tail point to null.
template <class T>
void IntSLList<T>::deleteFromHead() {
	if (head != 0) {
		IntSLLNode<T>* tmp;
		tmp = head;
		head = head->getNext();
		if (head == 0) {
			tail = 0;
		}
		delete tmp;
	}
}

//
template <class T>
void IntSLList<T>::deleteFromTail() {
	if (head != 0) {
		IntSLLNode <T>* tmp;
		tmp = head;
		if (head != tail) {
			while (tmp->getNext() != tail) {
				tmp = tmp->getNext();
			}
			tail = tmp;
			tmp = tmp->getNext();
			tail->setNext(0);
		}
		else {
			head = tail = 0;
		}
		delete tmp;
	}
}

//
template <class T>
bool IntSLList<T>::isEmpty() {
	bool res;
	res = false;
	if (head == 0) {
		res = true;
	}
	return res;
}

//
template <class T>
void IntSLList<T>::sortInsert(T val) {
	if (head == 0) {
		addToHead(val);
	}
	else {
		IntSLLNode<T>* tmp;
		IntSLLNode<T>* tmp2;
		tmp = head;
		tmp2 = 0;
		while ((val < tmp->getInfo()) && (tmp != tail)) {
			tmp2 = tmp;
			tmp = tmp->getNext();
		}
		if ((tmp == tail) && (val < tmp->getInfo())) {
			addToTail(val);
		}
		else {
			if ((tmp == head) && (val > tmp->getInfo())) {
				addToHead(val);
			}
			else {
				tmp2->setNext(new IntSLLNode<T>(val, tmp));
			}
		}
	}
}

//
template <class T>
void IntSLList<T>::printList() {
	IntSLLNode<T>* ptrNode;
	ptrNode = head;
	while (ptrNode != 0) {
		cout << ptrNode->getInfo() << " ";
		ptrNode = ptrNode->getNext();
	}
}

//
template <class T>
void IntSLList<T>::deleteButHead() {
	while (head != tail) {
		deleteFromTail();
	}
}

//
template <class T>
void IntSLList<T>::deleteButTail() {
	while (tail != head) {
		deleteFromHead();
	}
}

//
template <class T>
void IntSLList<T>::addIn(int pos, int val) {
	int i = 1;
	int count = 3;
	IntSLLNode<T>* tmp;
	IntSLLNode<T>* tmp2;
	IntSLLNode<T>* tmp3;
	tmp = head;
	tmp2 = 0;
	tmp3 = head;
	while (tmp3 != 0) {
		tmp3 = tmp3->getNext();
		count++;
	}
	if (pos == count) {
		while (i < pos) {
			tmp2 = tmp;
			tmp = tmp->getNext();
			i++;
		}
		tmp2->setNext(new IntSLLNode<T>(val, 0));
		tail = tmp2->getNext();
	}
	else {
		while (i < pos) {
			tmp2 = tmp;
			tmp = tmp->getNext();
			i++;
		}
		tmp2->setNext(new IntSLLNode<T>(val, tmp));
	}
}