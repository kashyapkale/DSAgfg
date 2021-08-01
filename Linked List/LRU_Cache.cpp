//https://practice.geeksforgeeks.org/problems/lru-cache/1
class LRUCache
{
public:
class Node {
public:
int key;
int value;
Node* next;
Node* prev;

Node(int key_, int value_)
{
  key = key_;
  value = value_;
  next = NULL;
  prev = NULL;
}
};

int limit;
Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);;
unordered_map<int, Node*> umap;

//Constructor for initializing the cache capacity with the given value.
LRUCache(int cap)
{
  limit = cap;
  head->next = tail;
  tail->prev = head;
}

void addNode(Node* newNode)
{
  Node* temp = head->next;

  head->next = newNode;
  newNode->next = temp;
  temp->prev = newNode;
  newNode->prev = head;
}

void deleteNode(Node* delNode)
{
  Node* prevTemp = delNode->prev;
  Node* nextTemp = delNode->next;

  prevTemp->next = nextTemp;
  nextTemp->prev = prevTemp;
}

//Function to return value corresponding to the key.
int get(int key)
{
  int val = -1;

  if (umap.find(key) != umap.end())
    {
      Node* tempNode = umap[key];
      val = tempNode->value;
      umap.erase(key);
      deleteNode(tempNode);
      //Node* newTemp = new Node(tempNode->key,tempNode->value);
      addNode(tempNode);
      umap[key] = head->next;
    }

  return val;
}

//Function for storing key-value pair.
void set(int key, int value)
{
  if (umap.find(key) != umap.end())
    {
      Node* temp = umap[key];
      deleteNode(temp);
      umap.erase(key);
    }

  if (limit == umap.size())
    {
      umap.erase(tail->prev->key);
      deleteNode(tail->prev);
    }
  addNode(new Node(key, value));
  umap[key] = head->next;
}
};
