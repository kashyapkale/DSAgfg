//https://practice.geeksforgeeks.org/problems/reorder-list/1
Node* reverseLL(Node* head)
{
  Node* prev = NULL;
  Node* next = NULL;
  Node* curr = head;

  while (curr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
  return prev;
}

void reorderList(Node* head)
{
  //Step1 Get Middle of the linked list
  Node* fast = head;
  Node* slow = head;
  Node* middle;

  while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
  middle = slow;

  //step 2 reverse
  middle->next = reverseLL(middle->next);


  //step 3 merge
  Node* curr1 = head;
  Node* curr2 = middle->next;

  while (curr2)
    {
      Node* next1 = curr1->next;
      Node* next2 = curr2->next;
      curr1->next = curr2;
      curr2->next = next1;
      curr1 = next1;
      curr2 = next2;
    }
  middle->next = NULL;
}
