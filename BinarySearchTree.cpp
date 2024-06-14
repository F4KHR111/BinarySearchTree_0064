#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string info;
	Node* leftchild;
	Node* rightchild;

	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
    Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL;

	}

    void insert(string element)
    {
    Node* newNode = new Node(element, NULL, NULL);
	newNode->info = element;
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;

	Node* parent = NULL;
	Node* currentNode = NULL;
	search(element, parent, currentNode);
	if (parent == NULL)
	{
		ROOT = newNode;
		return;
	}

	if (element < parent->info)

    {
		parent->leftchild = newNode;
	}

	else if (element > parent->info)

	{
		parent->rightchild = newNode;
	}
    }

    void search(string element, Node*& parent, Node*& currentNode) {  // Locate the node which will be the parent of the new node
		// This function searches the current Node of the specified Node as well as the currentNode of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {  // While the currentNode is not NULL and the value in the data field of the currentNode is not equal to the value in the data field of the new node
			parent = currentNode;  // Make the parent point to the currentNode
            if (element < currentNode->info) {  // If the value in the data field of the new node is less than the value in the data field of the currentNode
				currentNode = currentNode->leftchild;  // Make the currentNode point to the left child of the currentNode
			}
            else {  // If the value in the data field of the new node is greater than the value in the data field of the currentNode
				currentNode = currentNode->rightchild;  // Make the currentNode point to the right child of the currentNode
			}
		}
	}
void inorder(Node* ptr) // function to perform inorder traversal
	{
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild); // left
			cout << ptr->info << " "; // root
			inorder(ptr->rightchild); // right
		}
	}

    void preorder(Node* ptr) // function to perform inorder traversal
	{
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << " "; // root
			preorder(ptr->leftchild); // left
			preorder(ptr->rightchild); // right
		}
	}
void postorder(Node* ptr) // function to perform inorder traversal
	{
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			postorder(ptr->leftchild); // left
			postorder(ptr->rightchild); // right
			cout << ptr->info << " "; // root
		}
	}
};


