//https://practice.geeksforgeeks.org/problems/construct-tree-1/1
int search(int key, int start, int end, int in[]) {
	for (int i = start; i <= end; i++) {
		if (in[i] == key)
			return i;
	}

	return -1;
}

Node* buildTreeUtil(int in[], int pre[] , int &head, int start, int end) {
	if (end < start)
		return NULL;

	Node* root = new Node(pre[head]);
	int mid = search(pre[head], start, end, in);
	//cout<<in[mid]<<endl;
	head++;

	if (end == start)
		return root;
	root->left = buildTreeUtil(in, pre, head, start, mid - 1);
	root->right = buildTreeUtil(in, pre, head, mid + 1, end);

	return root;
}



Node* buildTree(int in[], int pre[], int n)
{
	int head = 0;
	return buildTreeUtil(in, pre, head, 0, n - 1);
}
