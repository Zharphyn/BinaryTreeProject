#pragma once

using namespace std;

template<typename T>
class TreeNode {
public:

	TreeNode();
	TreeNode(shared_ptr<T> data);
	~TreeNode();

private:
	shared_ptr<T> mData; // the data in the node
	shared_ptr<TreeNode> mLeft; // pointer to the left item in the node
	shared_ptr<TreeNode> mRight; // pointer to the right item in the node
	weak_ptr<TreeNode> parent;


};

	template<typename T>
	TreeNode<T>::TreeNode()
	{
		mData = 0;
		leftPtr = nullptr;
		rightPtr = nullptr;
		parent = nullptr;
	}


	template<typename T>
	TreeNode<T>::TreeNode(shared_ptr<T> data)
	{
		mData = data;
		leftPtr = nullptr;
		rightPtr = nullptr;
		parent = nullptr;
	}

	template<typename T>
	TreeNode<T>::~TreeNode()
	{
		leftPtr = nullptr;
		rightPtr = nullptr;
		parent = nullptr;
	}
