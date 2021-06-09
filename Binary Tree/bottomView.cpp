//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
vector <int> bottomView(Node *root)
{
	vector<int> ans;

	if (!root)
		return ans;

	int maximum = INT_MIN;
	int minimum = INT_MAX;
	unordered_map<int, vector<int>> umap;
	queue<pair<Node*, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		Node* temp = q.front().first;
		int level = q.front().second;
		if (temp->left)
			q.push(make_pair(temp->left, level - 1));
		if (temp->right)
			q.push(make_pair(temp->right, level + 1));
		umap[level].push_back(temp->data);
		q.pop();

		if (level > maximum)
			maximum = level;

		if (level < minimum)
			minimum = level;
	}

	for (int i = minimum; i <= maximum; i++)
		ans.push_back(umap[i][umap[i].size() - 1]);


	return ans;
}
