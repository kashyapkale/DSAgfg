//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#
//0.03sec
int KthSmallestElement(Node *root, int &K)
{
	if (K == 0 || !root)
		return -1;

	int A = KthSmallestElement(root->left, K);
	        if (A != -1)
		        return A;

	K--;
	if (K == 0)
		return root->data;
  
	int B = KthSmallestElement(root->right, K);
	        if (B != -1)
		        return B;

	return -1;
}
