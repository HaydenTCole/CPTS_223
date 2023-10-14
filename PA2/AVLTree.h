#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

template <typename T>
class AVLTree {
public:
	AVLNode<T>* _root;

	AVLTree() //Constructor
	{
		this->_root = nullptr;
	}

	~AVLTree() //Destructor
	{
		if (this->_root) {
			DestructorHelper(this->_root);
		}
	}
	/////////////////////////////////////////////////////////////////////////////////// Destructor help function
	void DestructorHelper(AVLNode<T>* node) //Uses recursion to help the destructor eliminate all nodes
	{
		if (node) {
			DestructorHelper(node->left);
			DestructorHelper(node->right);
			delete node;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////
	int height(AVLNode<T>* root) //Returns the height of the leaf
	{
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(height(root->left), height(root->right));
		}
	}

	/////////////////////////////////////////////////////////////////////////////////// Insert help functions
	void add(T val)
	{
		if (this->_root) {
			this->insert(val, this->_root);
		}
		else {
			this->_root = new AVLNode<T>(val);
		}
		
	}

	/*
	void rotate(AVLNode<T>* parent)
	{
		if (parent)
		{
			if (parent->left)
			{
				rotate(parent->left);
				if (parent->left->left && !parent->right) //Case 1
				{
					rotateWithLeftChild(parent);
				}
				else if (parent->left->right && !parent->right) //Case 2
				{
					doubleWithLeftChild(parent);
				}
			}
			if (parent->right)
			{
				if (parent->right->left && !parent->left) //Case 3
				{
					doubleWithRightChild(parent);
				}
				else if (parent->right->right && !parent->left) //Case 4
				{
					rotateWithRightChild(parent);
				}
				rotate(parent->right);
			}
		}
	}

	void rotateWithLeftChild(AVLNode<T>* parent) //Single left rotation (Case 1)
	{
		AVLNode<T>* parenttemp = new AVLNode<T>(0);
		AVLNode<T>* parentleft = new AVLNode<T>(0);
		AVLNode<T>* parentright = new AVLNode<T>(0);

		parenttemp = parent->left;
		parentleft = parent->left->left;
		parentright = parent;

		parent->left->left = NULL;
		parent = parenttemp;
		parent->right = parentright;
		parent->left = parentleft;

		parent->height = max(height(parent->left), height(parent->right)) + 1;
		parent->left->height = parent->height + 1;
		parent->right->height = parent->height + 1;
	}

	void rotateWithRightChild(AVLNode<T>* parent) //Single right rotation (Case 4)
	{
		AVLNode<T>* parenttemp = new AVLNode<T>(0);
		AVLNode<T>* parentleft = new AVLNode<T>(0);
		AVLNode<T>* parentright = new AVLNode<T>(0);

		parenttemp = parent->right;
		parentright = parent->right->right;
		parentleft = parent;

		parent->right->right = NULL;
		parent = parenttemp;
		parent->right = parentright;
		parent->left = parentleft;

		parent->height = max(height(parent->left), height(parent->right)) + 1;
		parent->left->height = parent->height + 1;
		parent->right->height = parent->height + 1;
	}

	void doubleWithLeftChild(AVLNode<T>* parent) //Double rotation left-right (Case 3)
	{
		rotateWithRightChild(parent->left);
		rotateWithLeftChild(parent);
	}

	void doubleWithRightChild(AVLNode<T>* parent) //Double rotation right-left (Case 4)
	{
		rotateWithLeftChild(parent->right);
		rotateWithRightChild(parent);
	}
	*/
	///////////////////////////////////////////////////////////////////////////////////
	void insert(T val, AVLNode<T>* root) //Inserts node with value <T> into the tree and rotates appropriately
	{
		if (val < root->value) {
			if (!root->left) {
				root->left = new AVLNode<T>(val);
			}
			else {
				insert(val, root->left);
			}
		}
		else if (val > root->value) {
			if (!root->right) {
				root->right = new AVLNode<T>(val);
			}
			else {
				insert(val, root->right);
			}
		}
		else {
			cout << "Something went wrong in the Insert function" << endl;
		}
		root->height = max(height(root->right), height(root->left)) + 1;
		//rotate(root);
	}

	int containsHelp(AVLNode<T>* root, T val)
	{
		if (root) {
			if (root->value == val) {
				return 1;
			}
			else if (root->value < val) {
				containsHelp(root->right, val);
			}
			else if (root->value > val) {
				containsHelp(root->left, val);
			}
			else {
				cout << "Something went wrong with the contains function" << endl;
			}
		}
		return 0;
	}

	int validateHelp(AVLNode<T>* root)
	{
		if (root) {
			validateHelp(root->left);
			validateHelp(root->right);
			if (height(root->right) - height(root->left) == 2 ||
				height(root->left) - height(root->right) == 2) {
				return 0;
			}
		}
		return 1;
	}

	/////////////////////////////////////////////////////////////////////////////////// Testing help function
	int validate()
	{
		return validateHelp(this->_root);
	}

	int contains(T val)
	{
		return containsHelp(this->_root, val);
	}

	AVLNode<T>* FindDeepestNode(AVLNode<T>* node, int current_level, int max_level, int deepest_node)
	{
		if (node) {
			FindDeepestNode(node->left, ++current_level, max_level, deepest_node);
			if (current_level > max_level) {
				deepest_node = node->value;
				max_level = current_level;
			}
			FindDeepestNode(node->right, current_level, max_level, deepest_node);
		}
		return node;	
	}

	int treeHeight()
	{
		return height(FindDeepestNode(this->_root, 0, 0, 0));
	}

	void printInOrderHelper(AVLNode<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	void print()
	{
		printInOrderHelper(this->_root);
	}
};

#endif

