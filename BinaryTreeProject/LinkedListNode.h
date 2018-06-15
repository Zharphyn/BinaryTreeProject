#pragma once

template<typename T>
class LinkedListNode
{
public:

	LinkedListNode();
	LinkedListNode(T data);
	~LinkedListNode();


	T mData; // the data in the node
	LinkedListNode<T>* mNext;	// pointer to the next one in the chain
	LinkedListNode<T>* mLast;   // pointer to the previous node in the chain
};

template<typename T>
LinkedListNode<T>::LinkedListNode()
{
	mData = 0;
	mNext = nullptr;
	mLast = nullptr;
}


template<typename T>
LinkedListNode<T>::LinkedListNode(T data)
{
	mData = data;
	mNext = nullptr;
	mLast = nullptr;
}

template<typename T>
LinkedListNode<T>::~LinkedListNode()
{
	mNext = nullptr;
	mLast = nullptr;
}
