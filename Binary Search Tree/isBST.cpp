https://practice.geeksforgeeks.org/problems/check-for-bst/0/
//On gfg one testcase is in complete (12  4) , which should be (12 4 N)
bool isBST(Node* root) 
    {
        static int prev = -1;
        if(!root)
            return true;
        bool A = isBST(root->left);
        if(!A)
            return false;
        if(root->data<prev)
            return false;
        prev = root->data;
        bool B = isBST(root->right);
        if(!B)
            return false;
        
        return true;
        
    }

//Update : Below is the most efficient solution for the problem passing all the testcases
bool isBSTUtil(Node* root, int max, int min){
    if (!root)
        return true;

    if (root->data > max || root->data < min)
        return false;

    bool leftTree = true, rightTree = true;

    if (root->right)
        rightTree = (root->right->data > root->data) && isBSTUtil(root->right, max, root->data);
    if (root->left)
        leftTree = (root->left->data < root->data) && isBSTUtil(root->left, root->data, min);

    return rightTree && leftTree;
}



bool isBST(Node* root){
    return isBSTUtil(root, INT_MAX, INT_MIN);
}
