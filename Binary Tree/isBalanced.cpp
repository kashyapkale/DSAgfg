//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
bool isBalancedTree(Node *root, int &height){
    if (root == NULL) {
        height = 0;
        return true;
    }

    if (!root->left && !root->right) {
        height = 1;
        return true;
    }

    int lh, rh;
    bool leftTree, rightTree;

    leftTree = isBalancedTree(root->left, lh);
    rightTree = isBalancedTree(root->right, rh);
    height = max(lh, rh) + 1;
    return leftTree && rightTree && (abs(lh - rh) <= 1);

}

bool isBalanced(Node* root) {
    int height = 0;

    return isBalancedTree(root, height);
}
