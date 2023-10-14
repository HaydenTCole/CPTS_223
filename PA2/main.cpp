/*
Project: Programming Assignment #2
Name: Hayden Cole
Date: 10/12/2023
Description: Implementing an AVL Binary Search Tree
*/

#include "AVLTree.h"

int main(void)
{
	///////////////////////////////////////////////////////////////////////////////////// Derive data sequences
	int count = 1;
	int index = 0;
	int arr_asc[50] = {}; //Array of ascending odd numbers
	int arr_desc[50] = {}; //Array of descending odd numbers
	int arr_rand[50] = {}; //Array of random odd numbers

	for (count; count < 100; count++) { //Loop for ascending order
		if (count % 2 == 1) { //Inserts odd number into ascending array
			arr_asc[index] = count; index++;
		}
	} count = 0; index--;

	for (index; index >= 0; index--) { //Loop for descending order
		arr_desc[count] = arr_asc[index]; //'index' counts down while 'count' counts up
		count++;
	} count = 0;

	vector<int> random = {};
	for (count; count < 50; count++) { //Loop for random order
		random.push_back(arr_asc[count]);
	} count = 0; index++;
	unsigned num = chrono::system_clock::now().time_since_epoch().count();
	shuffle(random.begin(), random.end(), default_random_engine(num));
	/////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////// Derive tree structures
	AVLTree<int>* tree_ascending = new AVLTree<int>(); //Initializing ascending tree
	AVLTree<int>* tree_descending = new AVLTree<int>(); //Initializing descending tree
	AVLTree<int>* tree_random = new AVLTree<int>(); //Initializing random tree

	while (count < 50) //Inserts the three data sequences into their respective trees
	{
		tree_ascending->add(arr_asc[count]);
		tree_descending->add(arr_desc[count]);
		tree_random->add(random[count]);
		count++;
	}
	tree_ascending->print(); cout << "\n";
	tree_descending->print(); cout << "\n";
	tree_random->print(); cout << "\n";
	/////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////// Test trees
	cout << "Testing height" << endl;
	cout << "1. Ascending Order AVL Tree height: " << tree_ascending->treeHeight() << endl;
	cout << "2. Descending Order AVL Tree height: " << tree_descending->treeHeight() << endl;
	cout << "3. Random Order AVL Tree height: " << tree_random->treeHeight() << endl; cout << "\n"; cout << "\n";

	cout << "Testing validate" << endl;
	cout << "1. Ascending Order AVL Tree validation: " << tree_ascending->validate() << endl;
	cout << "2. Descending Order AVL Tree validation: " << tree_descending->validate() << endl;
	cout << "3. Random Order AVL Tree validation: " << tree_random->validate() << endl; cout << "\n";

	int success = 1;
	cout << "Testing contains" << endl;
	while (index <= 100)
	{
		count = tree_ascending->contains(index);
		if (index % 2 == 0 && count == 1)
		{
			cout << "My AVL tree implementation is wrong" << endl;
			success = 0;
		}
		count = tree_descending->contains(index);
		if (index % 2 == 0 && count == 1)
		{
			cout << "My AVL tree implementation is wrong" << endl;
			success = 0;
		}
		count = tree_random->contains(index);
		if (index % 2 == 0 && count == 1)
		{
			cout << "My AVL tree implementation is wrong" << endl;
			success = 0;
		}
		index++;
	}
	
	if (success == 1)
	{
		cout << "Contains test successful" << endl;
	}

	return 0;
}
