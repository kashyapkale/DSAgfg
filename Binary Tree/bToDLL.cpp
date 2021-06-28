//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
void convert(Node *root, Node **head)
{
    if(root==NULL)return;
    static Node* prev=NULL;
    
    convert(root->left,head);
    
    if(*head==NULL)
    {
          prev=NULL; 
        *head=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    
    convert(root->right,head);
}


Node* bToDLL(Node *root)
{
	Node *head = NULL;
	convert(root, &head);
	return head;
}
