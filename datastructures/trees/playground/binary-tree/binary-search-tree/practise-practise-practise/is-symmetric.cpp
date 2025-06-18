
bool are_symmetric(node *lht, node *rht)
{
    if (lht == nullptr && rht == nullptr)
        return true;

    if (!(lht && rht && lht->data == rht->data))
        return false;

    return are_symmetric(lht->left, rht->right) &&
           are_symmetric(lht->right, rht->left);
}

bool is_symmetric(node *tree)
{
    if (tree == nullptr)
        return true;
    return are_symmetric(tree->left, tree->right);
}
