#pragma once
#include "BSTNode.h"

template <class T>
class BSTree
{
public:
	BSTree(); //Default Constructor
	~BSTree(); //Destructor (dealocate memory)
	void insert(T val); //Creates a new node with val as info
	bool remove(T val); //Removes the first node with val as info, if the node is removed it returns true, otherwise, false
	BSTNode<T>* search(T val); //Returns a pointer to node with val as info
	bool isEmpty(); //Checks if the tree if empty, if it is it returns true, otherwise, false
	void printInOrder(); //Prints InOrder Traversal
	void printPreOrder(); //Prints PreOrder Traversal
	void printPostOrder(); //Prints PostOrder Traversal

private:
	BSTNode<T>* root; //Pointer to first node
	void visitInOrder(BSTNode<T>* node); //Recursive support method for printInOrder()
	void visitPreOrder(BSTNode<T>* node); //Recursive support method for printPreOrder()
	void visitPostOrder(BSTNode<T>* node); //Recursive support method for printPostOrder()
	void removePostOrder(BSTNode<T>* node); //Recursive support method for ~BSTree() (Destructor)
	BSTNode<T>* recursiveSearch(BSTNode<T>* node, T val); //Recursive support method for search()
	bool recursiveSearchForRemove(BSTNode<T>* node, T val); //Recursive support method for remove()
	BSTNode<T>* findLowest(BSTNode<T>* node); //Extract the lowest node in a subtree rooted on node
};

template <class T>
BSTree<T>::BSTree() {
	root = 0;
}

template <class T>
BSTree<T>::~BSTree() {

}

template <class T>
void BSTree<T>::insert(T val) {
	if (root == 0) { //If tree is empty
		root = new BSTNode<T>(0, val, 0); //Make the new node the root
	}
	else { //If tree is not empty
		BSTNode<T>* tmp; //New temp for root
		BSTNode<T>* sRoot; //New temp for sub root
		tmp = root;
		sRoot = tmp;
		while (tmp != 0) { //While tmp has not found a leaf
			sRoot = tmp;
			if (val < sRoot->getInfo()) { //If val is lower than the node's info, go left
				tmp = tmp->getLeft();
			}
			else { //If val is higher than the node's info, go right
				tmp = tmp->getRight();
			}
		}
		if (val < sRoot->getInfo()) {
			sRoot->setLeft(new BSTNode<T>(0, val, 0)); //Insert new node at the left of sRoot
		}
		else {
			sRoot->setRight(new BSTNode<T>(0, val, 0)); //Insert new node at the right of sRoot
		}
	}
}

template <class T>
bool BSTree<T>::remove(T val) {
	bool res = false;
	if (root != 0) {
		if (root->getInfo == val) {
			if ((root->getLeft() == 0) && (root->getRight() == 0)) {
				delete root;
				root = 0;
			}
			else {
				BSTNode<T>* tmp;
				tmp = root;
				if (root->getLeft() == 0) {
					root = root->getRight();
				}
				else if (root->getRight() == 0) {
					root = root->getLeft();
				}
				else {
					BSTNode<T>* lowest;
					lowest = findLowest(root->getRight());
					if (root->getRight() == lowest) {
						lowest->setLeft(root->getLeft());
						root = lowest;
					}
					else {
						root = lowest;
						root->setLeft(tmp->getLeft());
						root->setRight(tmp->getRight());
					}
				}
				delete tmp;
			}
			res = true;
		}
		else {
			res = recursiveSearchForRemove(root, val);
		}
		return res;
	}
}

template <class T>
BSTNode<T>* BSTree<T>::search(T val) {
	return recursiveSearch(root, val);
}

template <class T>
bool BSTree<T>::isEmpty() {
	bool res;
	res = false;
	if (root == 0) {
		res = true;
	}
	return res;
}

template <class T>
BSTNode<T>* BSTree<T>::recursiveSearch(BSTNode<T>* node, T val) {
	BSTNode<T>* res; //Result
	res = 0; //Initializing 
	if (node != 0) {
		if (val == node->getInfo()) {
			res = node;
		}
		else if (val < node->getInfo()) {
			res = recursiveSearch(node->getLeft(), val);
		}
		else {
			res = recursiveSearch(node->getRight(), val);
		}
	}
	return res;
}

template <class T>
void BSTree<T>::printInOrder() {
	visitInOrder(root);
}

template <class T>
void BSTree<T>::printPreOrder() {
	visitPreOrder(root);
}

template <class T>
void BSTree<T>::printPostOrder() {
	visitPostOrder(root);
}

template <class T>
void BSTree<T>::visitInOrder(BSTNode<T>* node) {
	if (node != 0) {
		visitInOrder(node->getLeft());
		cout << "\n" << node->getInfo();
		visitInOrder(node->getRight());
	}
}

template <class T>
void BSTree<T>::visitPreOrder(BSTNode<T>* node) {
	if (node != 0) {
		cout << "\n" << node->getInfo();
		visitPreOrder(node->getLeft());
		visitPreOrder(node->getRight());
	}
}

template <class T>
void BSTree<T>::visitPostOrder(BSTNode<T>* node) {
	if (node != 0) {
		visitPostOrder(node->getLeft());
		visitPostOrder(node->getRight());
		cout << "\n" << node->getInfo();
	}
}

template <class T>
bool BSTree<T>::recursiveSearchForRemove(BSTNode<T>* node, T val) {
	bool res;
	BSTNode<T>* tmp;
	BSTNode<T>* found;
	if ((node->getLeft() != 0) && (val < node->getInfo())) {
		if (node->getLeft()->getInfo() == val) {
			found = node->getLeft();
			if (found->getRight() == 0) {
				node->setLeft(found->getLeft());
			}
			else {
				tmp = findLowest(found->getRight());
				node->setLeft(tmp);
			}
			res = true;
		}
		else {
			res = recursiveSearchForRemove(node->getLeft(), val);
		}
	}
	else if ((node->getRight() != 0) && (val > node->getInfo())) {
		if (node->getRight()->getInfo() == val) {
			found = node->getRight();
			if (found->getRight() == 0) {
				node->setRight(found->getLeft());
			}
			else {
				tmp = findLowest(found->getRight());
				node->setRight(tmp);
			}
			res = true;
		}
		else {
			res = recursiveSearchForRemove(node->getRight(), val);
		}
		return res;
	}
}

template <class T>
BSTNode<T>* BSTree<T>::findLowest(BSTNode<T>* node) {
	BSTNode<T>* tmp;
	if (node->getLeft() == 0) {
		tmp = node;
	}
	else {
		while (node->getLeft()->getLeft() != 0)
			node = node->getLeft();
		tmp = node->getLeft();
		node->setLeft(tmp->getRight());
	}
	return tmp;
}