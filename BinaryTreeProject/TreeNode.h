#pragma once

template<typename T>
class TreeNode {
public:

	TreeNode();
	TreeNode(T data);
	~TreeNode();


	T mData; // the data in the node
	TreeNode<T>* mLeft;	// pointer to the left item in the node
	TreeNode<T>* mRight;   // pointer to the right item in the node


	template<typename T>
	TreeNode<T>::TreeNode()
	{
		mData = 0;
		mLeft = nullptr;
		mRight = nullptr;
	}


	template<typename T>
	TreeNode<T>::TreeNode(T data)
	{
		mData = data;
		mLeft = nullptr;
		mRight = nullptr;
	}

	template<typename T>
	TreeNode<T>::~TreeNode()
	{
		mLeft = nullptr;
		mRight = nullptr;
	}

};