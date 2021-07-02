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
