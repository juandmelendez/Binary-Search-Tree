#pragma once
#include <iostream>
using namespace std;

template <class T>
class BSTNode {

public: 
	BSTNode(); //Default Constructor
	BSTNode(BSTNode<T>*, T, BSTNode<T>*);
	T getInfo();
	BSTNode<T>* getLeft();
	BSTNode<T>* getRight();
	void setInfo(T);
	void setLeft(BSTNode<T>*);
	void setRight(BSTNode<T>*);

private:
	BSTNode<T>* left;
	T info;
	BSTNode<T>* right;
};

//
template <class T>
BSTNode<T>::BSTNode() {
	right = left = 0;
}

//
template <class T>
BSTNode<T>::BSTNode(BSTNode<T>* l, T i, BSTNode<T>* r) {
	left = l;
	info = i;
	right = r;
}

//
template <class T>
T BSTNode<T>::getInfo() {
	return info;
}

//
template <class T>
BSTNode<T>* BSTNode<T>::getLeft() {
	return left;
}

//
template <class T>
BSTNode<T>* BSTNode<T>::getRight() {
	return right;
}

//
template <class T>
void BSTNode<T>::setInfo(T i) {
	info = i;
}

//
template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* l) {
	left = l;
}

//
template <class T>
void BSTNode<T>::setRight(BSTNode<T>* r) {
	right = r
}