//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
//O(N) Solution
int diameter(TreeNode* root, int *height) {
    if (!root) {
        *height = 0;
        return 0;
    }

    int lh, rh;
    int leftDiameter = diameter(root->left, &lh);
    int rightDiameter = diameter(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(max(leftDiameter, rightDiameter), lh + rh + 1);

}
    
int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return diameter(root,&height);
    }
