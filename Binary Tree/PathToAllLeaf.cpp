//https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/

//Used Backtracking in solution
//Can also be done using stack
void rec(Node* node, vector<vector<int>> &ans, vector<int> &temp) {
	if (!node)
		return;
	temp.push_back(node->data);
	if (!node->right && !node->left) {
		ans.push_back(temp);
		return;
	}

	if (node->left) {
		rec(node->left, ans, temp);
		temp.pop_back();
	}
	if (node->right) {
		rec(node->right, ans, temp);
		temp.pop_back();
	}

	return;
}


vector<vector<int>> Paths(Node* root)
{
	vector<vector<int>> ans;
	vector<int> temp;
	rec(root, ans, temp);
	return ans;
}
