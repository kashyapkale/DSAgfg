//https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/0/
void modifyUtil(Node *root, int &sum){
	if (!root)
		return;

	modifyUtil(root->right, sum);
	sum += root->data;
	root->data = sum;
	modifyUtil(root->left, sum);
}

Node* modify(Node *root){
	int sum = 0;

	modifyUtil(root, sum);
	return root;
}
