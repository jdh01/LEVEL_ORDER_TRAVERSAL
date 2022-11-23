#include <iostream>
#include <queue>

struct Node {
	char data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL; //intialise left and right to NULL
	return newNode;
}

Node* Insert(Node** root, int data) {
	if (root == NULL) {
		*root = GetNewNode(data);
		return *root;
	}
	else if (data <= (*root)->data) {
		(*root)->left = Insert((*root).left, data);
	}
	else {
		(*root)->right = Insert(root->right, data);
	}
	return *root;
}

void LevelOrder(Node *root)
{
	std::queue<Node*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while (!Q.empty()) {
		Node* current = Q.front();
		std::cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}

int main()
{
	Node* root = NULL;
	Insert(root, 1);
	Insert(root, 2);
	Insert(root, 3);
	Insert(root, 4);
	Insert(root, 5);
	Insert(root, 6);
	Insert(root, 7);

	LevelOrder(root);

}