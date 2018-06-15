#pragma once
#include "LinkedListNode.h"

template<typename T>
class LinkedList
{
public:

	LinkedList(); // constructor
	~LinkedList(); // destructor

	void AddNodeAtHead(T* pData); // creates node with data at the start of the linked list
	void AddNodeAtTail(T* pData); // creates node with data at the end of the linked list

	T* GetHead() const; // return head data
	T* GetTail() const; // return tail data
	int GetSize() const; // return the number of nodes
	T* GetNodeAt(int nIndex) const; // return data at index

	void RemoveNodeAt(int nIndex); // remove node at index
	bool RemoveNode(T* pData); // find and remove node via comparing data (return value is if removed or not)

	LinkedList* Clone() const; // clones the current linked list, creating a new independent one

private:

	LinkedListNode<T>* mHead;
	LinkedListNode<T>* mTail;
};


//Constructor
template<typename T>
LinkedList<T>::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;

}


// creates node with data at the start of the linked list
template<typename T>
void LinkedList<T>::AddNodeAtHead(T* pData)
{
	LinkedListNode<T>* pNode = new LinkedListNode<T>(*pData);

	if (mHead == nullptr)
	{
		this->mHead = pNode;
		this->mTail = pNode;
	}
	else
	{
		pNode->mNext = mHead;
		this->mHead->mLast = pNode;
		this->mHead = pNode;
	}

}

// creates node with data at the end of the linked list
template<typename T>
void LinkedList<T>::AddNodeAtTail(T* pData)
{
	LinkedListNode<T>* pNode = new LinkedListNode<T>(*pData);

	if (mHead == nullptr)
	{
		this->mHead = pNode;
		this->mTail = pNode;
	}
	else
	{
		mTail->mNext = pNode;
		pNode->mLast = this->mTail;
		mTail = mTail->mNext;
	}
}

// return head data
template<typename T>
T* LinkedList<T>::GetHead() const
{
	T value = this->mHead->mData;
	return &value;
}

// return tail data
template<typename T>
T* LinkedList<T>::GetTail() const
{
	return &this->mTail->mData;
}

// return the number of nodes
template<typename T>
int LinkedList<T>::GetSize() const
{
	LinkedListNode<T>* pNode = new LinkedListNode<T>();
	int counter = 0;
	if (this->mHead != nullptr) 
	{
		pNode = this->mHead;
		counter++;
	}
	while (pNode->mNext != nullptr)
	{
		counter++;
		pNode = pNode->mNext;
	}
	return counter;
}

// return data at index
template<typename T>
T* LinkedList<T>::GetNodeAt(int nIndex) const
{

	LinkedListNode<T>* pNode = new LinkedListNode<T>();
	int counter = 0;
	if (this->mHead != nullptr) 
	{
		pNode = this->mHead;
		counter++;
	}

	while (pNode->mNext != nullptr && counter != nIndex)
	{
		counter++;
		pNode = pNode->mNext;
	}
		if (counter == nIndex) 
		{
			return &pNode->mData;
		}
		else
		{
			throw std::invalid_argument("Node not found");
		}
}

// remove node at index
template<typename T>
void LinkedList<T>::RemoveNodeAt(int nIndex)
{
	LinkedListNode<T>* pNode = new LinkedListNode<T>();
	
	int counter = 0;
	if (this->mHead != nullptr) // If there is data in the list
	{
		pNode = this->mHead;
		counter++;
	}

	while (pNode->mNext != nullptr && counter != nIndex)
	{
		counter++;
		pNode = pNode->mNext;
	}

	if (counter == nIndex) // if we found the node
	{
		if (pNode == mHead)
		{
			mHead = pNode->mNext;
			mHead->mLast = nullptr;
			pNode->mNext = nullptr;
			
			pNode = nullptr;
		}
		else if (pNode == mTail)
		{
			mTail = pNode->mLast;
			mTail->mNext = nullptr;

			pNode = nullptr;
		}
		else
		{
			LinkedListNode<T>* pNode2 = new LinkedListNode<T>();
			pNode2 = pNode->mLast;
			pNode = pNode->mNext;
			pNode2->mNext = pNode;
			pNode->mLast = pNode2;

			pNode2 = nullptr;
			pNode = nullptr;
		}
	}
	else
	{
		throw std::invalid_argument("Node not found");
	}
}

// find and remove node via comparing data (return value is if removed or not)
template<typename T>
bool LinkedList<T>::RemoveNode(T* pData)
{
	LinkedListNode<T>* pNode = new LinkedListNode<T>();

	if (this->mHead != nullptr) 
	{
		pNode = this->mHead;
	}

	while (pNode->mNext != nullptr && pNode->mData != *pData)
	{
		pNode = pNode->mNext;
	}

	if (pNode->mData == *pData)
	{
		if (pNode == mHead)
		{
			mHead = pNode->mNext;
			mHead->mLast = nullptr;
			pNode->mNext = nullptr;

			pNode = nullptr;
		}
		else if (pNode == mTail)
		{
			mTail = pNode->mLast;
			mTail->mNext = nullptr;

			pNode = nullptr;
		}
		else
		{
			LinkedListNode<T>* pNode2 = new LinkedListNode<T>();
			pNode2 = pNode->mLast;
			pNode = pNode->mNext;
			pNode2->mNext = pNode;
			pNode->mLast = pNode2;

			pNode2 = nullptr;
			pNode = nullptr;
		}
		return true;
	}
	else
	{
		return false;
	}
}

// clones the current linked list, creating a new independent one
template<typename T>
LinkedList<T>* LinkedList<T>::Clone() const
{
	LinkedList<T>* newList = new LinkedList<T>();
	LinkedListNode<T>* pNode = new LinkedListNode<T>();

	pNode = this->mHead;

	newList->AddNodeAtHead(&pNode->mData);
	if (newList->mHead != nullptr) 
	{
		pNode = this->mHead;
		while (pNode->mNext != nullptr)
		{
			pNode = pNode->mNext;
			newList->AddNodeAtTail(&pNode->mData);
		}
	}
	
	return newList;
}


