bool isFullTree(struct Node* root){
	if (!root)
		return true;
	if (!root->right && !root->left)
		return true;
	bool leftTree, rightTree;

	if (root->left)
		leftTree = isFullTree(root->left);
	else
		return false;

	if (root->right)
		rightTree = isFullTree(root->right);
	else
		return false;

	if (leftTree && rightTree)
		return true;

	return false;
}
