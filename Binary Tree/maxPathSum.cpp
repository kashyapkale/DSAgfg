//https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
//max path sum : Difficult
int mpsDriver(TreeNode* root, int &sum) {
    if (!root) {
        return 0;
    }

    //Max Path Sum of left subtree
    //Max Path Sum of right subtree
    

    int rSumPath;
    int lSumPath;

    lSumPath = mpsDriver(root->left, sum);
    rSumPath = mpsDriver(root->right, sum);

    int tempSum = max(root->val, (max(lSumPath, rSumPath) + root->val));

    int maximum = max(tempSum, lSumPath + rSumPath + root->val);

    sum = max(maximum, sum);
    return tempSum;

}
    
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        mpsDriver(root,sum);
        return sum;
    }
