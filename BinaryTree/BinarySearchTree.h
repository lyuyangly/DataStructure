/*
 *****************************************************************************************
 *	File:		BinarySearchTree.h
 *	Author:		Lyu Yang
 *	Function:	
 *	Description: A simple template  log2(N)
 *
*****************************************************************************************
*/

#pragma once

#include <ostream>
#include <cstddef>

template <typename T> class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	BinarySearchTree(const BinarySearchTree &rhs)
	{
		if(this != &rhs) {
			makeEmpty();
			root = clone(rhs.root);
		}
	}

	~BinarySearchTree()
	{
		makeEmpty();
	}

	bool contains(const T& x) const
	{
		return contains(x, root);
	}

	bool isEmpty() const
	{
		return (root == NULL) ? true : false;
	}
	
	/* delete all resources of the binary tree */
	void makeEmpty()
	{
		makeEmpty(root);
	}

	void insert(const T &x)
	{
		insert(x, root);
	}

	void remove(const T &x)
	{
		remove(x, root);
	}
	
	/* = operator */
	const BinarySearchTree& operator=(const BinarySearchTree &rhs)
	{
		if(this != &rhs) {
			makeEmpty();
			root = clone(rhs.root);
		}
		return *this;
	}

	/* traverse methods */
	void traverseTree(std::ostream &os)
	{
		if(isEmpty()) {
			os << "Empty Tree." << std::endl;
			return ;
		}

		inordertraverse(root, os);
	}

private:
	struct BinaryNode
	{
		T element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode(const T &theElement, BinaryNode *lt, BinaryNode *rt)
			: element(theElement), left(lt), right(rt)
		{  }
	};

	/* class template private members */
	BinaryNode *root;
	
	/* insert a node to the sorted binary tree */
	void insert(const T &x, BinaryNode * &t) const
	{
		if(t == NULL)
			t = new BinaryNode(x, NULL, NULL);
		else if(x < t->element)
			insert(x, t->left);
		else if(x > t->element)
			insert(x, t->right);
		else
			;
	}

	/* remove an node in the binary tree */
	void remove(const T &x, BinaryNode * &t) const
	{
		if(t == NULL)
			return ;
		if(x < t->element)
			remove(x, t->left);
		else if(x > t->element)
			remove(x, t->right);
		else if(t->left != NULL && t->right != NULL) {
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		} else {
			// with only child only or no child
			BinaryNode *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
	}

	BinaryNode * findMin(BinaryNode *t) const
	{
		if(t == NULL)
			return NULL;
		if(t->left == NULL)
			return t;
		return findMin(t->left);
	}

	BinaryNode * findMax(BinaryNode *t) const
	{
		if(t != NULL)
			while(t->right != NULL)
				t = t->right;
		return t;
	}

	bool contains(const T &x, BinaryNode *t) const
	{
		if(t == NULL)
			return false;
		else if(x < t->element)
			return contains(x, t->left);
		else if(x > t->element)
			return contains(x, t->right);
		else
			return true;
	}

	void makeEmpty(BinaryNode *t) const
	{
		if(t != NULL) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = NULL;
	}
	
	BinaryNode *clone(BinaryNode *t) const
	{
		if(t == NULL)
			return NULL;
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
	}

	/* private traversal methods */
	void inordertraverse(BinaryNode *t, std::ostream &os) const
	{
		if(t != NULL) {
			inordertraverse(t->left, os);
			os << t->element << std::endl;
			inordertraverse(t->right, os);
		}	
	}
	
	void preordertraverse(BinaryNode *t, std::ostream &os) const
	{
		if(t != NULL) {
			os << t->element << std::endl;
			inordertraverse(t->left, os);
			inordertraverse(t->right, os);
		}	
	}
	
	void postordertraverse(BinaryNode *t, std::ostream &os) const
	{
		if(t != NULL) {
			inordertraverse(t->left, os);
			inordertraverse(t->right, os);
			os << t->element << std::endl;
		}	
	}
};



