#include <iostream>
#include <queue>

struct Node {
	int data;
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
	if (*root == NULL) {
		*root = GetNewNode(data);
		return *root;
	}
	else if (data <= (*root)->data) {
		(*root)->left = Insert(&(*root)->left, data);
	}
	else {
		(*root)->right = Insert(&(*root)->right, data);
	}
	return *root;
}

void LevelOrder(Node *root)
{
	if (root == NULL) return;
	std::queue<Node*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while (!Q.empty()) {
		Node* current = Q.front();
		Q.pop();
		std::cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
	}
}

int main()
{
	Node* root = NULL;
	Insert(&root, 15);
	Insert(&root, 20);
	Insert(&root, 13);
	Insert(&root, 45);
	Insert(&root, 5);
	Insert(&root, 16);
	Insert(&root, 27);

	LevelOrder(root);

}