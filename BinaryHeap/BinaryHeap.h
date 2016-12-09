/*
 *	Binary Heap
 *	root index is i:
 *	if array index from 1: lchild = 2*i, rchild = 2*i+1, for index x, it's root index is x/2.
 *
 *	if array index from 0: lchild = 2*i+1, rchild = 2*i+2, for index x, it's root index is (x - 1)/2.
 *
 */

#pragma once

#include <iostream>
#include <vector>

template <typename T> class BinaryHeap
{
public:
	explicit BinaryHeap() : currentSize(0)
	{ }
	explicit BinaryHeap(const std::vector<T> &items) : array(items.size() + 10), currentSize(items.size())
	{
		for(size_t i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];
		buildHeap();
	}
	
	~BinaryHeap()
	{
		currentSize = 0;
		array.clear();
	}

	bool isEmpty() const
	{
		return (currentSize == 0);
	}

	/*
	 *	Put the element at the last position,
	 *	then percolate up it.
	 */
	void insert(const T &x)
	{
		if(currentSize == array.size() - 1)
			array.resize(array.size() * 2);

		size_t hole = ++currentSize;

		for(; hole > 1 && x < array[hole / 2]; hole /= 2)
			array[hole] = array[hole / 2];
		array[hole] = x;
	}

	void deleteMin()
	{
		if(isEmpty())
			return ;
		// Since the array index of root is from 1.
		array[1] = array[currentSize--];
		percolateDown(1);
	}

	void deleteMin(T &minItem)
	{
		if(isEmpty())
			return ;
		minItem = array[1];
		// Same as before.
		array[1] = array[currentSize--];
		percolateDown(1);
	}

	std::vector<T> array;
private:
	size_t currentSize;
	
	// for cout
	// std::vector<T> array;

	void buildHeap()
	{
		// begin at the last parent node of binary tree. root index start at 1.
		for(size_t i = currentSize / 2; i > 0; --i)
			percolateDown(i);
	}
	
	/*
	 *	percolate down operation
	 *	check that one root may has or not has lchild & rchild
	 *
	 *
	 */
	void percolateDown(size_t hole)
	{
		size_t child;
		T tmp = array[hole];

		for(; hole * 2 <= currentSize; hole = child) {
			child = hole * 2;
			if(child != currentSize && array[child + 1] < array[child])
				child++;
			
			if(array[child] < tmp)
				array[hole] = array[child];
			else 
				break;
		}
		array[hole] = tmp;
	}
};





