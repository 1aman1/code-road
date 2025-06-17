int height(tNode *pRoot)
{
  return pRoot == nullptr ? 0 : 1 + max(height(pRoot->left), height(pRoot->right));
}