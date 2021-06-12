//https://practice.geeksforgeeks.org/problems/sum-tree/1#
//0.02sec solution
bool leaf(Node* root) {
	if (!root)
		return false;

	if (!root->right && !root->left)
		return true;

	return false;

}

int getVal(Node* root) {
	if (!root)
		return 0;

	return root->data;
}


bool isSumTree(Node* root)
{
	//if root is a leaf node or NULL return true
	if (!root || leaf(root))
		return true;

	//both cild are leaf
	if (leaf(root->right) && leaf(root->left))
		return (getVal(root->left) + getVal(root->right) == root->data);
	//one of the child is root
	else if (leaf(root->right))
		return isSumTree(root->left) && ((2 * getVal(root->left)) + getVal(root->right) == root->data);

	else if (leaf(root->left))
		return isSumTree(root->right) && ((2 * getVal(root->right)) + getVal(root->left) == root->data);
	//none of the child is root
	else
		return isSumTree(root->right) && isSumTree(root->left) && (root->data == 2 * (getVal(root->left) + getVal(root->right)));

}
