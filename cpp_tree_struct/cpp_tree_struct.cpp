#include <iostream>
#include <vector>

using std::vector;
using std::cout;

struct Node
{
	int data;
	struct Node * parent;
	vector<struct Node *> children;
};

void setupRoot(struct Node** root, int node_data)
{
	struct Node* newNode = new Node;
	newNode->data = node_data;
	newNode->parent = NULL;
	(*root) = newNode;
}

void addChild(struct Node* parent, int node_data)
{
	struct Node* newNode = new Node;
	newNode->data = node_data;
	newNode->parent = parent;
	parent->children.push_back(newNode);
}

void removeChild(struct Node* parent, int childId)
{
	struct Node* childToKill = parent->children[childId];
	delete childToKill;
	parent->children.erase(parent->children.begin() + childId);
}

void printNodeData(struct Node * nodeToPrint)
{
	if (nodeToPrint != NULL)
		cout << nodeToPrint->data << "\n";
	else
		cout << "NULL";
}

void printChildren(struct Node * nodeToPrint)
{
	if (nodeToPrint->children.size() > 0)
		for (int i = 0; i < nodeToPrint->children.size(); i++)
		{
			printNodeData(nodeToPrint->children[i]);
			printChildren(nodeToPrint->children[i]);
		}
}


void printTree(struct Node * root)
{
	struct Node * cnode = root;
	cout << "Root: ";
	printNodeData(root);
	cout << "\n";
	printChildren(root);
}


int main()
{
	struct Node * tree = NULL;
	setupRoot(&tree, 10);
	addChild(tree,20);
	addChild(tree,21);
	addChild(tree,22);
	addChild(tree->children[0], 30);
	addChild(tree->children[0], 31);
	addChild(tree->children[0], 32);
	addChild(tree->children[1], 40);
	addChild(tree->children[1], 41);
	addChild(tree->children[1], 42);
	addChild(tree->children[2], 50);
	addChild(tree->children[2], 51);
	addChild(tree->children[2], 52);
	addChild(tree->children[1]->children[1], 60);
	addChild(tree->children[1]->children[1], 61);
	addChild(tree->children[1]->children[1], 62);
	printTree(tree);
	system("pause");
}