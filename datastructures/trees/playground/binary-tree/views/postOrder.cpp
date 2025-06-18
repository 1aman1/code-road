#include <iostream>
#include <memory>

using namespace std;

struct Node
{
    int m_data;
    unique_ptr<Node> m_left;
    unique_ptr<Node> m_right;

    Node(int val) : m_data(val),
                    m_left(nullptr),
                    m_right(nullptr) {}
};

using NodePtr = unique_ptr<Node>;

class Tree
{
private:
    NodePtr m_root{nullptr};

public:
    void insertNode(int aVal);
    void viewPostOrder();

private:
    NodePtr insertNodeHelper(NodePtr aCurrNode, int aVal);
    void postOrderHelper(Node *aCurrNode);
};

void Tree::insertNode(int aVal)
{
    m_root = insertNodeHelper(std::move(m_root), aVal);
}

NodePtr Tree::insertNodeHelper(NodePtr currNode, int aVal)
{
    if (!currNode)
    {
        return make_unique<Node>(aVal);
    }
    else
    {
        if (aVal < currNode->m_data)
        {
            currNode->m_left = insertNodeHelper(std::move(currNode->m_left), aVal);
        }
        else
        {
            currNode->m_right = insertNodeHelper(std::move(currNode->m_right), aVal);
        }
    }

    return currNode;
}

void Tree::viewPostOrder()
{
    postOrderHelper(m_root.get());
}

void Tree::postOrderHelper(Node *currNode)
{
    if (currNode)
    {
        postOrderHelper(currNode->m_left.get());
        postOrderHelper(currNode->m_right.get());
        cout << currNode->m_data << " ";
    }
}

int main()
{
    cout << "Building " << __FILE__ << endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);

    tree.viewPostOrder();

    return 0;
}
