#include <stdlib.h>
#include <stdio.h>
#include <iostream>	
#include <iomanip>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

struct Tree
{
	Node *root;
};

// insert list item into node
void insert(struct Tree *tree, struct Node *p_tree, struct Node *node)
{
	// tree empty
	if (tree->root == NULL)
	{
		tree->root = node;
		tree->root->left = NULL;
		tree->root->right = NULL;
	}
	else
	{
		// think of parent as the 'previous' ptr in linked lists 
		// needed to keep track of where to insert new node
		Node *parent;

		// this will be our main traversal ptr think 'current' in linked lists
		Node *current = tree->root; 

		// only needed for BST to avoid duplicates
		bool found = false; 

		// traverse down the tree, take 'left' or 'right' paths depending on node->data 
		// do this until we hit NULL which implies the parent is a 'leaf' node
		while (current != NULL && !found)
		{
			parent = current;
			if (node->data > current->data)
				current = current->right;
			else if (node->data < current->data)
				current = current->left;
			else
				found = true; //if we want a regular Binary Tree, just assign NULL to current here
		}

		//if only needed if we want BST
		if (!found) 
		{
			if (node->data > parent->data)
				parent->right = node;
			else
				parent->left = node;
		}

	}
}

// list contents of Binary Tree in ascending order
void inOrder(struct Node *p_tree)
{
	if (p_tree != NULL)
	{
		inOrder(p_tree->left);
		cout << p_tree->data << "\t";
		inOrder(p_tree->right);
	}
}

void TreeSort()
{
	int *treeList = new int[ARRAY_SIZE];
	
	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		treeList[i] = g_pUnsorted[i];
	}

	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << treeList[i] << "\t";

	cout << "\n\n";

	struct Tree *tree = (Tree *)malloc(sizeof(struct Tree));
	tree->root = NULL;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// allocate memory for new node here and simply pass it by ptr reference
		// then simply insert node at the end of list in 'insert' function
		// must allocate here NOT in switch case statements due to build errors
		Node *node = (Node *)malloc(sizeof(struct Node));

		// must initialize new node's value and next ptr after allocation or else crash occurs
		node->data = treeList[i];

		// must init node links to NULL
		node->left = NULL;
		node->right = NULL;

		// prep work done? lets insert the item into the tree
		insert(tree, tree->root, node);

	}

	printf("\nAfter:\n");
	inOrder(tree->root);
	cout << "\n" << tree->root->data << "\t";

}


