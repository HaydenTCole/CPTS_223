#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	void printLevelOrderHelper(Node<T>* root, int level, int current)
	{
		if (root)
		{
			if (current == level + 1)
			{
				if (root->left && root->right)
				{
					cout << root->left->value; cout << " "; cout << root->right->value << endl;
				}
				else if (root->left && !root->right)
				{
					cout << root->left->value << endl;
				}
				else if (!root->right && root->left)
				{
					cout << root->right->value << endl;
				}
				else
				{
					return;
				}
			}
			else
			{
				current++;
				if (root->left)
				{
					printLevelOrderHelper(root->left, level, current);
				}
				else if (root->right)
				{
					printLevelOrderHelper(root->right, level, current);
				}
			}
		}
	}

	int getPathLength(Node<T>* root)
	{
		int count = 0;
		if (root)
		{
			if (root->left)
			{
				count++;
				getPathLength(root->left);
			}
			else if (root->right)
			{
				count++;
				getPathLength(root->right);
			}
		}
		return count;
	}

	void printMaxPathHelper(Node<T>* root)
	{
		if (root)
		{
			cout << root->value << " ";

			if (!root->left || !root->right)
			{
				if (root->left)
				{
					printMaxPathHelper(root->left);
				}
				if (root->right)
				{
					printMaxPathHelper(root->right);
				}
			}
			else if (root->left && root->right)
			{
				if (getPathLength(root->left) > getPathLength(root->right))
				{
					printMaxPathHelper(root->left);
				}
				else if (getPathLength(root->left) < getPathLength(root->right))
				{
					printMaxPathHelper(root->right);
				}
			}
		}
	}

	bool containsHelper(Node<T>* root, T value)
	{
		if (root)
		{
			if (root->value == value)
			{
				cout << "Value found" << endl;
				return true;
			}
			else if (root->value > value)
			{
				containsHelper(root->left, value);
			}
			else if (root->value < value)
			{
				containsHelper(root->right, value);
			}
		}	
		else
		{
			cout << "Value not found" << endl;
			return false;
		}
		
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	
	void destroyTree(Node<T>* root)
	{
		if (root)
		{
			destroyTree(root->left);
			destroyTree(root->right);
			delete root;
		}
	}
	
	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST() {
		destroyTree(this->_root);
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder() {
		int totallevels = heightHelper(this->_root);
		int currentlevel = 0;

		if (this->_root)
		{
			cout << this->_root->value << endl; //Prints out the root node first

			while (currentlevel != totallevels) //Iterates until all levels are accounted for
			{
				printLevelOrderHelper(this->_root, currentlevel, 1); //Recursively finds the nodes in a certain level
				currentlevel++;
			}
		}
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath() {
		printMaxPathHelper(this->_root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	bool contains(T value) {
		return containsHelper(this->_root, value);;
	}
};

#endif


