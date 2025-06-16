

class BrowserHistory
{
  struct Listnode
  {
  public:
    string val;
    Listnode *prev;
    unique_ptr<Listnode> next;

    Listnode(string val, Listnode *prev = nullptr, Listnode *next = nullptr)
        : val(val), prev(prev), next(next) {}
  };

  unique_ptr<Listnode> head;
  Listnode *curr;

public:
  BrowserHistory(string homepage)
  {
    head = make_unique<Listnode>(homepage);
    curr = head.get();
  }

  void visit(string url)
  {
    curr->next = make_unique<Listnode>(url, curr);
    curr = curr->next.get();
  }

  string back(int steps)
  {
    while (curr->prev != nullptr && steps-- > 0)
    {
      curr = curr->prev;
    }
    return curr->val;
  }

  string forward(int steps)
  {
    while (curr->next != nullptr && steps-- > 0)
    {
      curr = curr->next.get();
    }
    return curr->val;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */