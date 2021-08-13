//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
bool isIdentical(Node* p, Node* q) {
        if (!p && !q)
                return true;

        if (!p || !q)
                return false;

        if (p->data == q->data)
                return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);

        return false;
}
