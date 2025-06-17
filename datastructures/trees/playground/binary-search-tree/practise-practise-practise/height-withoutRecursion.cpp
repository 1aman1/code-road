
void heightNonRecursively(tNode *pRoot)
{
  queue<tNode *> Q;
  size_t count = 0;
  tNode *temp = NULL;
  Q.push(pRoot);
  Q.push(NULL);

  while (!Q.empty())
  {
    temp = Q.front();
    Q.pop();

    if (temp == NULL)
    {
      if (!Q.empty())
        Q.push(NULL);
      ++count; // increment level
    }
    else
    {
      if (temp->left)
        Q.push(temp->left);
      if (temp->right)
        Q.push(temp->right);
    }
  }

  while (Q.empty())
    Q.pop();
  cout << count << endl;
}
