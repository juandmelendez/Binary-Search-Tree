#pragma once
#include "IntDLLNode.h"
#include <iostream>
using namespace std;

template <class T>
class circDLList {

public:
	circDLList();
	~circDLList();
	void addToHead(T val);
	void addToTail(T val);
	void deleteFromHead();
	void deleteFromTail();
	bool isEmpty();
	void sortInsert(T val);
	void insert(int pos, T val);
	void printList();
	void printRevList();

private:
	IntDLLNode<T>* head;
};

//
template <class T>
circDLList<T>::circDLList() {
	head = 0;
}

//
template <class T>
circDLList<T>::~circDLList() {
	while (!isEmpty()) {
		this->deleteFromHead();
	}
}

//
template <class T>
void circDLList<T>::addToHead(T val) {
	if (head != 0) {
		IntDLLNode<T>* tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
		head = tmp;
	}
	else {
		cout << "List is empty." << endl;
		head = new IntDLLNode<T>(0, val, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

//
template <class T>
void circDLList<T>::addToTail(T val) {
	if (head != 0) {
		IntDLLNode<T>* tmp;
		tmp = new IntDLLNode<T>(head->getPrev(), val, head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
	}
	else {
		head = new IntDLLNode<T>(0, val, 0);
		head->setPrev(head);
		head->setNext(head);
	}
}

//
template <class T>
void circDLList<T>::deleteFromHead() {
	if (head != 0) {
		IntDLLNode<T>* tmp;
		tmp = head;
		if (head == head->getNext()) {
			head = 0;
		}
		else {
			head->getNext()->setPrev(head->getPrev());
			head->getPrev()->setNext(head->getNext());
			head = head->getNext();
		}
		delete tmp;
	}
}

//
template <class T>
void circDLList<T>::deleteFromTail() {
	if (head != 0) {
		IntDLLNode<T>* tmp;
		tmp = head->getPrev();
		if (head == head->getNext()) {
			head = 0;
		}
		else {
			tmp->getPrev()->setNext(head);
			head->setPrev(tmp->getPrev());
		}
		delete tmp;
	}
}

//
template <class T>
bool circDLList<T>::isEmpty() {
	bool res;
	res = false;
	if (head == 0) {
		res = true;
	}
	return res;
}

//
template <class T>
void circDLList<T>::sortInsert(T val) {
	if (head == 0) {
		addToHead(val);
	}
	else {
		IntDLLNode<T>* tmp;
		IntDLLNode<T>* tmp2;
		tmp = head;
		tmp2 = 0;
		while ((val < tmp->getInfo()) && (tmp->getNext() != head)) {
			tmp2 = tmp;
			tmp = tmp->getNext();
		}
		if ((tmp->getNext() == head) && (val < tmp->getInfo())) {
			addToTail(val);
		}
		else {
			if ((tmp == head) && (val > tmp->getInfo())) {
				addToHead(val);
			}
			else {
				IntDLLNode<T>* newNode = new IntDLLNode<T>(tmp2, val, tmp);
				tmp2->setNext(newNode);
				tmp->setPrev(newNode);
			}
		}
	}
}

//
template <class T>
void circDLList<T>::printList() {
	IntDLLNode<T>* ptrNode;
	ptrNode = head;
	if (ptrNode != 0) {
		while (ptrNode->getNext() != head) {
			cout << ptrNode->getInfo() << " ";
			ptrNode = ptrNode->getNext();
		}
		cout << ptrNode->getInfo() << " ";
	}
}

//
template <class T>
void circDLList<T>::printRevList() {
	IntDLLNode<T>* ptrNode;
	ptrNode = head;
	if (ptrNode != 0) {
		while (ptrNode->getPrev() != head) {
			ptrNode = ptrNode->getPrev();
			cout << ptrNode->getInfo() << " ";
		}
		cout << head->getInfo() << " ";
	}
}

