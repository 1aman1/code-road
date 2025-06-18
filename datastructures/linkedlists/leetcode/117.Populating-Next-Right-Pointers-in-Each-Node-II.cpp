/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        std::queue<Node *> myQ;
        myQ.push(root);

        while (!myQ.empty())
        {
            int levelSize = myQ.size();

            Node *prev = nullptr;
            for( int i = 0 ; i < levelSize; ++i)
            {
                Node *currNode = myQ.front();
                myQ.pop();

                if (prev)
                {
                    prev->next = currNode;
                }
                prev = currNode;

                if (currNode->left)
                    myQ.push(currNode->left);
                if (currNode->right)
                    myQ.push(currNode->right);
            }
        }

        return root;
    }
};