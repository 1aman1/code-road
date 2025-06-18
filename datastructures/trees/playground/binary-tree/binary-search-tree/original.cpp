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
    void deleteNode(int aVal);

    void viewInOrder();

private:
    NodePtr insertNodeHelper(NodePtr aCurrNode, int aVal);
    NodePtr deleteNodeHelper(NodePtr aCurrNode, int aVal);

    Node *findSuccessor(Node *aCurrNode);
    void inOrderHelper(Node *aCurrNode);
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

void Tree::deleteNode(int aVal)
{
    if (m_root)
        m_root = deleteNodeHelper(std::move(m_root), aVal);
}

NodePtr Tree::deleteNodeHelper(NodePtr aCurrNode, int aVal)
{
    if (!aCurrNode)
    {
        return nullptr;
    }
    else if (aVal < aCurrNode->m_data)
    {
        aCurrNode->m_left = deleteNodeHelper(std::move(aCurrNode->m_left), aVal);
    }
    else if (aVal > aCurrNode->m_data)
    {
        aCurrNode->m_right = deleteNodeHelper(std::move(aCurrNode->m_right), aVal);
    }
    else
    {
        if (aCurrNode->m_left == nullptr &&
            aCurrNode->m_right == nullptr)
        {
            return nullptr;
        }
        else if (aCurrNode->m_left != nullptr &&
                 aCurrNode->m_right == nullptr)
        {
            return std::move(aCurrNode->m_left);
        }
        else if (aCurrNode->m_left == nullptr &&
                 aCurrNode->m_right != nullptr)
        {
            return std::move(aCurrNode->m_right);
        }
        else
        {
            Node *successorNode = findSuccessor(aCurrNode->m_right.get());
            aCurrNode->m_data = successorNode->m_data;
            aCurrNode->m_right = deleteNodeHelper(std::move(aCurrNode->m_right), successorNode->m_data);
        }
    }
    return aCurrNode;
}

void Tree::viewInOrder()
{
    inOrderHelper(m_root.get());
}

void Tree::inOrderHelper(Node *currNode)
{
    if (currNode)
    {
        inOrderHelper(currNode->m_left.get());
        cout << currNode->m_data << " ";
        inOrderHelper(currNode->m_right.get());
    }
}

Node *Tree::findSuccessor(Node *aCurrNode)
{
    while (aCurrNode && aCurrNode->m_left)
    {
        aCurrNode = aCurrNode->m_left.get();
    }

    return aCurrNode;
}

int main()
{
    cout << "Building " << __FILE__ << endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);

    tree.deleteNode(7);

    tree.viewInOrder();
    return 0;
}