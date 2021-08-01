//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#
Node *copyList(Node *head)
{
  Node* curr = head;

  while (curr)
    {
      Node* temp = curr->next;
      Node* dummy = new Node(curr->data);
      curr->next = dummy;
      dummy->next = temp;
      curr = temp;
    }


  curr = head->next;
  Node* prev = head;

  while (curr)
    {
      if (prev->arb)
        curr->arb = prev->arb->next;
      if (curr->next)
        {
          curr = curr->next->next;
          prev = prev->next->next;
          continue;
        }
      curr = NULL;
    }



  Node* dummyHead = new Node(-1);

  curr = head->next;
  prev = head;
  dummyHead->next = curr;
  while (curr->next)
    {
      prev->next = prev->next->next;
      curr->next = curr->next->next;
      prev = prev->next;
      curr = curr->next;
    }
  prev->next = NULL;

  return dummyHead->next;
}
