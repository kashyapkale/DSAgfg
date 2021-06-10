//https://practice.geeksforgeeks.org/problems/k-distance-from-root/1#
void hasKdistance(Node *root, int S, vector<int> &ans) {
	if (!root)
		return;

	if (S == 0) {
		ans.push_back(root->data);
		return;
	}

	hasKdistance(root->left, S - 1, ans);
	hasKdistance(root->right, S - 1, ans);
	return;
}

vector<int> Kdistance(struct Node *root, int k)
{
	vector<int> ans;
	hasKdistance(root, k, ans);
	return ans;
}
