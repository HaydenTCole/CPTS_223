#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

template <typename T>
class AVLNode {
public:
	T value;
	AVLNode* left;
	AVLNode* right;
	int height;

	AVLNode(T val)
	{
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
		height = 0;
	}

	~AVLNode()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
		height = 0;
	}
};

#endif
