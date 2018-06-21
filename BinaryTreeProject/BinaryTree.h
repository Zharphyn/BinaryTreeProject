#pragma once
#include <memory>
#include "TreeNode.h"

//  I should be able to add an item - Done
//	I should be able to print pre - order, in - order and post - order - Done
//	I should be able to remove an item - Done

template<typename T>
class BinaryTree
{
public:
	shared_ptr<TreeNode<T>> mRoot;

public:
	// constructor
	BinaryTree() 
	{
		mRoot = make_shared<TreeNode<T>>();
		mRoot->mData = 0;
		mRoot->mLeft = nullptr;
		mRoot->mRight = nullptr;

	}

	// constructor
	BinaryTree(shared_ptr<T> data)
	{
		mRoot = make_shared<TreeNode<T>>();
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
		pNode = mRoot;

		bool Found = false;
		while (!Found) {
			if (mRoot->mData.get() == nullptr) {// empty tree
				Found = true;
				mRoot = newNode;
			}
			else { 
				if ((*newNode->mData.get() >= *pNode->mData.get()) && (pNode->mData.get() != nullptr)) { // new data is less than current node's data - go left
					if (pNode->mRight.get() != nullptr) {
						pNode = pNode->mRight; // traverse right
					}
					else { // end of right branches
						Found = true;
						createRightChild(pNode, newNode);
					}
				}
				else { // new data is greater than or equal to current node's data - go left
					if (pNode->mLeft.get() != nullptr) {
						pNode = pNode->mLeft; // traverse left
					}
					else { // end of left branches
						Found = true;
						createLeftChild(pNode, newNode);
					}
				}
			}
 		}

		pNode = nullptr;

	}

	// Places a new node on the left side of the passed node 
	void createLeftChild(shared_ptr<TreeNode<T>> Parent, shared_ptr<TreeNode<T>> Node)
	{
		Parent->mLeft = Node;
		Node->parent = Parent;
	}

	// Places a new node on the right side of the passed node 
	void createRightChild(shared_ptr<TreeNode<T>> Parent, shared_ptr<TreeNode<T>> Node)
	{
		Parent->mRight = Node;
		Node->parent = Parent;
	}


	// The structure of the 3 print functions comes from https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
	// I had to adapt the functions to work with my tree

	/* Given a binary tree, print its nodes in inorder*/
	void printInorder(shared_ptr<TreeNode<T>> Node)
	{
		if (Node == nullptr) {
			return;
		}

		/* first recur on left child */
		printInorder(Node->mLeft);

		/* then print the data of node */
		printf("%d, ", *Node->mData.get());

		/* now recur on right child */
		printInorder(Node->mRight);
	}

	/* Given a binary tree, print its nodes according to the
	"bottom-up" postorder traversal. */
	void printPostorder(shared_ptr<TreeNode<T>> Node)
	{
		if (Node == nullptr) {
			return;
		}

		// first recur on left subtree
		printPostorder(Node->mLeft);

		// then recur on right subtree
		printPostorder(Node->mRight);

		// now deal with the node
		printf("%d, ", *Node->mData.get());
	}

	/* Given a binary tree, print its nodes in preorder*/
	void printPreorder(shared_ptr<TreeNode<T>> Node)
	{
		if (Node == nullptr) {
			return;
		}

		/* first print data of node */
		printf("%d, ", *Node->mData.get());

		/* then recur on left sutree */
		printPreorder(Node->mLeft);

		/* now recur on right subtree */
		printPreorder(Node->mRight);
	}

	// The structure of the delete function and the minValueNode function comes from https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
	// I had to adapt the function to work with my tree
	
	/* Given a non-empty binary search tree, return the node with minimum
	key value found in that tree. Note that the entire tree does not
	need to be searched. */
	shared_ptr<TreeNode<T>> minValueNode(shared_ptr<TreeNode<T>> Node)
	{
		shared_ptr<TreeNode<T>> current = Node;

		/* loop down to find the leftmost leaf */
		while (current->mLeft != nullptr) {
			current = current->mLeft;
		}
			
		return current;
	}

	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	shared_ptr<TreeNode<T>> deleteNode(shared_ptr<TreeNode<T>> Node, T key)
	{
		// base case
		if (Node == nullptr) {
			return Node;
		}

		// If the key to be deleted is smaller than the root's key,
		// then it lies in left subtree
		if (key < *Node->mData.get()) {
			Node->mLeft = deleteNode(Node->mLeft, key);
		}

		// If the key to be deleted is greater than the root's key,
		// then it lies in right subtree
		else if (key > *Node->mData.get()) {
			Node->mRight = deleteNode(Node->mRight, key);
		}

		// if key is same as root's key, then This is the node
		// to be deleted
		else
		{
			// node with only one child or no child
			if (Node->mLeft == nullptr)
			{
				shared_ptr<TreeNode<T>> temp = Node->mRight;
				return temp;
			}
			else if (Node->mRight == nullptr)
			{
				shared_ptr<TreeNode<T>> temp = Node->mLeft;
				return temp;
			}

			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			shared_ptr<TreeNode<T>> temp = minValueNode(Node->mRight);

			// Copy the inorder successor's content to this node
			*Node->mData.get() = *temp->mData.get();

			// Delete the inorder successor
			Node->mRight = deleteNode(Node->mRight, *temp->mData.get());
		}
		return Node;
	}

};