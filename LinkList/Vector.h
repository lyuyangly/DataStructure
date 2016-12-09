/*
 *****************************************************************************************
 *	File:
 *	Author:
 *	Function:
 *	Description:
 *
*****************************************************************************************
*/

#pragma once

template <typename T> class Vector {
public:
	explicit Vector(int initSize = 0)
		: theSize(initSize), theCapacity(initSize + SPACE_CAPACITY)
		{ objects = new T [ theCapacity ]; }
	Vector(const Vector &rhs) : objects(NULL)
	{ operator=(rhs); }
	~Vector()
	{ delete [] objects; }

	Vector& operator=(const Vector& rhs)
	{
		if(this != &rhs) {
			delete [] objects;
			theSize = rhs.size();
			theCapacity = rhs.theCapacity;

			objects = new T[capacity()];
			for(size_t k = 0; k < size(); ++k) {
				objects[k] = rhs.objects[k];
			}
		}
		return *this;
	}

	void resize(size_t newSize)
	{
		if(newSize > theCapacity)
			reserve(newSize * 2 + 1);
		theSize = newSize;
	}

	void reserve(size_t newCapacity)
	{
		if(newCapacity < theSize)
			return;
		T *oldArray = objects;
		objects = new T [newCapacity];
		for(size_t k = 0; k < theSize; ++k)
			objects[k] = oldArray[k];
		theCapacity = newCapacity;
		delete [] oldArray;
	}

	T& operator[](size_t index)
	{ return objects[index]; }
	const T& operator[](size_t index) const
	{ return objects[index]; }

	bool empty(void) const
	{ return size() == 0; }

	size_t size(void) const
	{ return theSize; }
	size_t capacity(void) const
	{ return theCapacity; }

	void push_back(const T &x)
	{
		if(theSize == theCapacity)
			reserve(2*theCapacity + 1);
		objects[theSize++] = x;
	}

	void pop_back(void)
	{ theSize--; }

	const T & back(void) const
	{ return objects[theSize - 1]; }

	typedef T * iterator;
	typedef const T * const_iterator;

	iterator begin(void)
	{ return &objects[0]; }

	const_iterator begin(void) const
	{ return &objects[0]; }

	iterator end(void)
	{ return &objects[size()]; }
	const_iterator end(void) const
	{ return &objects[size()]; }

	enum { SPACE_CAPACITY = 16 };

private:
	size_t theSize;
	size_t theCapacity;
	T * objects;
};










