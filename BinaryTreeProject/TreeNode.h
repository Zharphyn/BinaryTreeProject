#pragma once

using namespace std;

template<typename T>
class TreeNode {
public:

	TreeNode();
	TreeNode(shared_ptr<T> data);
	~TreeNode();

public:
	shared_ptr<T> mData; // the data in the node
	shared_ptr<TreeNode> mLeft; // pointer to the left item in the node
	shared_ptr<TreeNode> mRight; // pointer to the right item in the node
	shared_ptr<TreeNode> parent; // pointer to the node parent


};
	// default constructor
	template<typename T>
	TreeNode<T>::TreeNode()
	{
		mData = 0;
		mLeft = nullptr;
		mRight = nullptr;
		parent = nullptr;
	}

	// constructor
	template<typename T>
	TreeNode<T>::TreeNode(shared_ptr<T> data)
	{
		mData = data;
		mLeft = nullptr;
		mRight = nullptr;
		parent = nullptr;
	}

	// destructor
	template<typename T>
	TreeNode<T>::~TreeNode()
	{
		mLeft = nullptr;
		mRight = nullptr;
		parent = nullptr;
	}
