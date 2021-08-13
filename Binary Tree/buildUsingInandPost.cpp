//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
int search(int key, int start, int end, int in[]) {
	for (int i = start; i <= end; i++) {
		if (in[i] == key)
			return i;
	}

	return -1;
}

Node* buildTreeUtil(int in[], int post[] , int &head, int start, int end) {
	if (end < start)
		return NULL;

	Node* root = new Node(post[head]);
	int mid = search(post[head], start, end, in);
	head--;
	root->right = buildTreeUtil(in, post, head, mid + 1, end);
	root->left = buildTreeUtil(in, post, head, start, mid - 1);

	return root;
}



Node* buildTree(int in[], int post[], int n)
{
	int head = n - 1;
	return buildTreeUtil(in, post, head, 0, n - 1);
}
