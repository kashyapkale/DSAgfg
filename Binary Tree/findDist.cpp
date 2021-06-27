//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#
Node* lca(Node* root, int a, int b) {
	if (!root)
		return NULL;

	if (root->data == a || root->data == b)
		return root;

	Node* A = lca(root->left, a, b);
	Node* B = lca(root->right, a, b);

	if (A && B)
		return root;

	if (A)
		return A;
	else
		return B;

}



int distance(Node *root, int x)
{
    // Base case
    if (root == NULL)
      return -1;
 
    // Initialize distance
    int dist = -1;
 
    // Check if x is present at root or in left
    // subtree or right subtree.
    if ((root->data == x) ||
        (dist = distance(root->left, x)) >= 0 ||
        (dist = distance(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;
}

int findDist(Node* root, int a, int b) {
	Node* Lca = lca(root, a, b);

	if (!Lca)
		return -1;

	int d = distance(Lca, a) +  distance(Lca, b);
	
	return d;
}
