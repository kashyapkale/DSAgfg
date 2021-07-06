//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1#
Node* rotate(Node* head, int k)
{
	//1->2->75->12->41->3->98
	int temp = k - 1;
	Node* curr = head;
	Node* curr1 = head;

	int cnt = 1;

	while (curr->next) {
		curr = curr->next;
		//cnt++;
	}

	curr->next = head;

	while (cnt < k) {
		cnt++;
		curr1 = curr1->next;
	}

	head = curr1->next;
	curr1->next = NULL;
	return head;

}
