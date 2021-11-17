//https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/0/
void printNearNodesUtil(Node *root, int low, int high, vector<int> &ans){
        if (!root)
                return;
        if (root->data == high) {
                ans.push_back(root->data);
                printNearNodesUtil(root->left, low, high, ans);
                return;
        }

        if (root->data == low) {
                ans.push_back(root->data);
                printNearNodesUtil(root->right, low, high, ans);
                return;
        }

        if (root->data < low) {
                printNearNodesUtil(root->right, low, high, ans);
                return;
        }

        if (root->data > high) {
                printNearNodesUtil(root->left, low, high, ans);
                return;
        }

        ans.push_back(root->data);
        //cout<<root->data<<endl;
        printNearNodesUtil(root->left, low, root->data, ans);
        printNearNodesUtil(root->right, root->data, high, ans);
        return;
}

vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;

        printNearNodesUtil(root, low, high, ans);
        sort(ans.begin(), ans.end());
        return ans;
}
