#pragma once
#include <memory>
#include "TreeNode.h"

template<typename T>
class BinaryTree
{
private:
	shared_ptr<TreeNode<T>> mRoot;

public:
	// constructor
	BinaryTree() 
	{
		mRoot->mData = 0;
		mRoot->mLeft = nullptr;
		mRoot->mRight = nullptr;

	}

	// constructor
	BinaryTree(shared_ptr<T> data)
	{
		//mRoot = make_shared<TreeNode>();
		mRoot->mData = data;
		mRoot->mLeft = nullptr;
		mRoot->mRight = nullptr;
	}

	// Destructor
	~BinaryTree()
	{
		mRoot->mLeft = nullptr;
		mRoot->mRight = nullptr;
		mRoot = nullptr;
	}

	// Determines which side of current node to add
	// Traverses tree to find correct addition point
	// Adds node to the addition point determined
	void AddNode(shared_ptr<T> pData)
	{
		shared_ptr<TreeNode<T>> newNode = make_shared<TreeNode<T>>(pData);
		shared_ptr<TreeNode<T>> pNode = make_shared<TreeNode<T>>();
		pNode->parent = mRoot;

		bool Found = false;
		while (!Found) {
			if (pNode->parent != nullptr) {
				if (newNode->mData < pNode->mData) { // new data is less than current node's data - go right
					if (pNode->mRight != nullptr) {
						pNode->parent = pNode->mRight; // traverse right
					}
					else { // end of right branches
						found = true;
						createRightChild(pNode, newNode);
					}
				}
				else { // new data is greater than or equal to current node's data - go left
					if (pNode->mLeft != nullptr) {
						pNode->parent = pNode->mLeft; // traverse left
					}
					else { // end of left branches
						found = true;
						createLeftChild(pNode, newNode);
					}
				}
			}
			else { // empty tree
				Found = true;
				mRoot = newNode;
			}
		}

		pNode->parent = nullptr;
		delete pNode;
	}

	void createLeftChild(weak_ptr<TreeNode<T>> Parent, shared_ptr<TreeNode<T>> Node)
	{
		Parent->mLeft = Node;
		Node->parent = Parent;
	}

	void createRightChild(weak_ptr<TreeNode<T>> Parent, shared_ptr<TreeNode<T>> Node)
	{
		Parent->mRight = Node;
		Node->parent = Parent;
	}

	//  I should be able to add an item
	//	I should be able to print pre - order, in - order and post - order
	//	I should be able to remove an item

};