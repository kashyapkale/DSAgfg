//https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

pair<int, int> solution(Node *root, int K) {
	if (!root)
		return make_pair(-1, INT_MAX);

	pair<int, int> P(root->data, abs(K - root->data));
	pair<int, int> Q;
	if (root->data > K)
		Q = solution(root->left, K);
	else
		Q = solution(root->right, K);

	return (P.second < Q.second) ? P : Q;

}


int minDiff(Node *root, int K)
{
  
	return solution(root, K).second;
}
