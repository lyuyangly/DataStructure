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

template <typename _T> struct _ListNode
{
	_T val;
	struct _ListNode<_T> *pnext = NULL;
	_ListNode() : pnext(NULL) { }
	_ListNode(const _T &x) : val(x), pnext(NULL) { }
};

template <typename T> class LinkList
{
public:
	LinkList() : ptail(&head), m_len(0u) { }
	
	~LinkList() {
		_ListNode<T> *p, *q = &head;
		while((p = q) != NULL) {
			q = p->pnext;
			delete p;
		}
	}
	
	bool push_back(const T &x) {
		_ListNode<T> *p = new _ListNode<T>(x);
		ptail->pnext = p;
		ptail = p;
		++m_len;
		return true;
	}
	
	size_t getlength(void) {
		return m_len;
	}
	
	// Since = delete was introduce in c++11
	// LinkList(const LinkList<T> &) = delete;
	// LinkList<T>& operator=(const LinkList<T> &) const = delete;
	
private:
	_ListNode<T> head;
	_ListNode<T> *ptail;
	size_t m_len;
	LinkList(const LinkList<T> &);
	LinkList<T>& operator=(const LinkList<T> &) const;
};
