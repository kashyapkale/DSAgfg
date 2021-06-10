//https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
bool hasPathSum(Node *root, int S) {
	if (!root || S < 0)
		return false;

	if (!root->left && !root->right) {
		S = S - root->data;
		return (S == 0) ? true : false;
	}

	return hasPathSum(root->left, S - root->data) || hasPathSum(root->right, S - root->data);

}
