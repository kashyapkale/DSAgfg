//https://practice.geeksforgeeks.org/problems/symmetric-tree/1
//Mirror And Symmetry both codes are in same file
//Basically to check symmetry of the tree we can check if the mirror image of the tree is equal to the tree
bool mirror(Node* root1, Node* root2) {
	if (!root1 && !root2)
		return true;

	if (!root1 || !root2)
		return false;

	return (root1->data == root2->data) && mirror(root1->right, root2->left) && mirror(root1->left, root2->right);

}

bool isSymmetric(struct Node* root)
{
	if(!root)
	    return true;

    return mirror(root,root);
}
