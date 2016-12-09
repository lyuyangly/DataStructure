#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Test Begin!" << endl;

	BinarySearchTree<int> BSTree;
	
	for(size_t i = 0; i < 10; ++i)
		BSTree.insert(i);
	
	for(size_t i = 15; i > 5; --i)
		cout << BSTree.contains(i) << '\t';
	
	cout << endl;
	
	if(BSTree.contains(6)) {
		cout << "BSTree contains the element." << endl;
	} else {
		cout << "BSTree doesn't contains the element." << endl;
	}
	
	BSTree.remove(6);
	
	if(BSTree.contains(6)) {
		cout << "BSTree contains the element." << endl;
	} else {
		cout << "BSTree doesn't contains the element." << endl;
	}
	
	BSTree.traverseTree(cout);
	cout << "Test End!" << endl;
	return 0;
}

