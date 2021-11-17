//Morris Traversal
vector<int> morrisTraversal(Node* root){
	vector<int> inOrder(Node* root) {

		Node* curr = root;
		vector<int> inOrder;

		while (curr) {
			if (!curr->left) {
				inOrder.push_back(curr->data);
				curr = curr->right;
			}
			else{
				Node* prev = curr->left;
				while (prev->right && prev->right != curr) {
					prev = prev->right;
				}

				if (!prev->right) {
					prev->right = curr;
					curr = curr->left;
				}
				else{
					prev->right = NULL;
					inOrder.push_back(curr->data);
					curr = curr->right;
				}
			}
		}
		return inOrder;
	}
}
