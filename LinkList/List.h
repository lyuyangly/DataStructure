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

#include <cstddef>

template <typename T> class List {
public:
	/* the Node */
    struct Node {
        T data;
        struct Node *prev;
        struct Node *next;
        Node(const T& d = T(), Node *p = NULL, Node *n = NULL)
            : data(d), prev(p), next(n)
            { }
    };
	
	/* implementation of const iterator */
    class const_iterator {
	public:
		const_iterator() : current(NULL)
		{  }
		const T& operator*() const
		{
			return current->data;
		}

		const_iterator& operator++() // ++x
		{
			current = current->next;
			return *this;
		}

		const_iterator operator++(int)  // x++
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const const_iterator &rhs) const
		{ return current == rhs.current; }
		
		bool operator!=(const const_iterator &rhs) const
		{ return !(*this == rhs); }

		protected:
			Node *current;
			const_iterator(Node *p): current(p)
			{  }

		friend class List<T>;
    };

	/* implementation of iterator */
    class iterator : public const_iterator {
		public:
			iterator()
			{  }
			T& operator*(void)
			{
				return const_iterator::current->data;
			}
			const T& operator*() const
			{
				return current->data; 
			}

			iterator& operator++()
			{
				const_iterator::current = const_iterator::current->next;
				return *this;
			}
			iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}
		protected:
			iterator(Node *p) : const_iterator(p)
			{  }

		friend class List<T>;
    };
	
	/* Member method of List<T> */
    List(void)
    {
		init();
    }

    ~List(void)
    {
		clear();
		delete head;
		delete tail;
    }

	List(const List& rhs)
	{
		init();
		*this = rhs;
	}

    const List & operator=(const List& rhs)
    {
		if(this == &rhs)
			return *this;
		clear();
		for(const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr) {
			push_back(*itr);
		}
		return *this;
    }
	
	/* iterator operation for List<T> */
    iterator begin(void)
    {
        return iterator(head->next);
    }
    const_iterator begin(void) const
    {
        return const_iterator(head->next);
    }
    iterator end(void)
    {
        return iterator(tail);
    }
    const_iterator end(void) const
    {
        return const_iterator(tail);
    }

	/* general operation of container */
    size_t size(void) const
    { return theSize; }

    bool empty(void) const
    {
        return size() == 0;
    }

    void clear(void)
    {
        while(!empty()) {
            pop_front();
        }
    }

    T& front(void)
    {
        return *begin();
    }
    const T& front(void) const
    {
        return *begin();
    }
    T& back(void)
    {
        return *--end();
    }
    const T& back(void) const
    {
        return *--end();
    }
    void push_front(const T& x)
    {
        insert(begin(), x);
    }
    void push_back(const T& x)
    {
        insert(end(), x);
    }
    void pop_front(void)
    {
        erase(begin());
    }
    void pop_back(void)
    {
        erase(--end());
    }

    iterator insert(iterator itr, const T& x)
    {
		Node *p = itr.current;
		theSize++;
		return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
    }

    iterator erase(iterator itr)
    {
		Node *p = itr.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;
		return retVal;
    }
    iterator erase(iterator start, iterator end)
    {
		for(iterator itr = start; itr != end;)
			itr = erase(itr);
		return end;
    }


private:
    size_t theSize;
    Node *head;
    Node *tail;
    void init(void)
    {
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
    }
	const List<T> *theList;
	Node *current;
};

