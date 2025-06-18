class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return root;
        }

        queue<Node *> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty())
        {
            Node *prevNode = nullptr;

            int levelNodeCount = nodesQueue.size();

            for (int i = 0; i < levelNodeCount; ++i)
            {
                Node *currentNode = nodesQueue.front();
                nodesQueue.pop();

                if (prevNode)
                {
                    prevNode->next = currentNode;
                }
                prevNode = currentNode;

                if (currentNode->left)
                {
                    nodesQueue.push(currentNode->left);
                }
                if (currentNode->right)
                {
                    nodesQueue.push(currentNode->right);
                }
            }
        }

        return root;
    }
};