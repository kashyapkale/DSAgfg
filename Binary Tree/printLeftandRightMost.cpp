//https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1/
void printCorner(Node *root){
	queue<Node*> q;
	q.push(NULL);
	q.push(root);
	while (!q.empty()) {
		if (q.front() != NULL) {
			Node* temp = q.front();
			q.pop();
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		else if (!q.front() && q.size() > 1) {
			q.pop();
			if (q.size() > 1)
				cout << q.front()->data << " " << q.back()->data << " ";
			else
				cout << q.front()->data << " ";
			q.push(NULL);
		}
		else if (!q.front() && q.size() == 1) {
			q.pop();
		}

	}

}
