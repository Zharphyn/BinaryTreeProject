// BinaryTreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Writer.h"
#include "BinaryTree.h"
#include <iostream> // provides system("pause");
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

const int NumberToGenereate = 40; // number of random numbers to add to the tree for testing purposes
const int NumberToDelete = 10; // number of random numbers to generate to attempt deletion

int main()
{
	Writer W;

	srand((int)time(NULL)); // seeds the random number generator
	
	int Random = rand() % 100 + 1;
	shared_ptr<BinaryTree<int>> myTree = make_shared<BinaryTree<int>>(make_shared<int>(Random)); // Creates the tree, initializes with data

	Random = rand() % 100 + 1;
	shared_ptr<int> newData = make_shared<int>(Random); // creates a new smart pointer to use when adding data to the tree
	myTree->AddNode(newData); // Adds the newly created smart pointer to the tree

	for (int i = 0; i < NumberToGenereate; i++) { // create random dataset for testing
		Random = rand() % 100 + 1;
		newData = make_shared<int>(Random);
		myTree->AddNode(newData);
	}
	W.WriteToScreen("In Order");
	myTree->printInorder(myTree->mRoot); // print out the list, in order
	W.WriteToScreen("\n\nPreOrder");
	myTree->printPreorder(myTree->mRoot); // print out the list, preorder
	W.WriteToScreen("\n\nPostOrder");
	myTree->printPostorder(myTree->mRoot); // print out the list postorder
	W.WriteToScreen("\n");
	for (int i = 0; i < NumberToDelete; i++) {
		Random = rand() % 100 + 1;
		W.WriteToScreen("\nDelete {0}", to_string(Random));
		myTree->deleteNode(myTree->mRoot, Random); // Deletes the first node found with the value matching the Random number
	}
	W.WriteToScreen("\n\nIn Order");
	myTree->printInorder(myTree->mRoot); // reprint the list in order to see that the nodes to be deleted were deleted

	W.WriteToScreen("\n\n");
	system("pause");
    return 0;
}

