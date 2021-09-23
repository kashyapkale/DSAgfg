//https://practice.geeksforgeeks.org/problems/burning-tree/1#
//gfg Hard
Node* getTargetNode(Node* root, int target, unordered_map<Node*, Node*> &parents){
    stack<Node*> s;
    Node* ans = NULL;

    s.push(root);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        if (temp->right) {
            parents[temp->right] = temp;
            s.push(temp->right);
        }
        if (temp->left) {
            parents[temp->left] = temp;
            s.push(temp->left);
        }
        if (temp->data == target)
            ans = temp;
    }

    return ans;

}

int minTime(Node* root, int target){
    //Traverse the tree to fill parents hashmap and find target node
    if (!root)
        return 0;

    unordered_map<Node*, Node*> parents;
    Node* targetNode = getTargetNode(root, target, parents);
    unordered_map<Node*, int> visited;
    queue<pair<Node*, int> > q;
    int timeTaken = 0;

    q.push(make_pair(targetNode, 1));
    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        int level = temp.second + 1;
        q.pop();
        if (temp.first->left && !visited[temp.first->left]) {
            q.push(make_pair(temp.first->left, level));
            visited[temp.first->left] = 1;
        }
        if (temp.first->right && !visited[temp.first->right]) {
            q.push(make_pair(temp.first->right, level));
            visited[temp.first->right] = 1;
        }
        if (parents.find(temp.first) != parents.end() && !visited[parents[temp.first]]) {
            q.push(make_pair(parents[temp.first], level));
            visited[parents[temp.first]] = 1;
        }
        //cout<<temp.second<<endl;
        if (q.empty())
            timeTaken = temp.second;
    }

    return timeTaken - 1;
}
