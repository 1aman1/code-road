#include <iostream>

struct Node
{
    int m_data;
    Node *m_left;
    Node *m_right;

    Node(int aNewm_Data) : m_data(aNewm_Data),
                           m_left(nullptr),
                           m_right(nullptr) {}
};

class Tree
{
private:
    Node *m_root{nullptr};

public:
    void insertNode(int aVal);
    void deleteNode(int aVal);

    void viewInOrder();

private:
    Node *insertNodeHelper(Node *aCurrNode, int aVal);
    Node *deleteNodeHelper(Node *aCurrNode, int aVal);
    Node *findSuccessor(Node *aCurrNode);

    void inOrderHelper(Node *aCurrNode);
};

void Tree::insertNode(int aVal)
{
    m_root = insertNodeHelper(m_root, aVal);
}

Node *Tree::insertNodeHelper(Node *currNode, int aVal)
{
    if (!currNode)
    {
        currNode = new Node(aVal);
    }
    else
    {
        if (aVal < currNode->m_data)
        {
            currNode->m_left = insertNodeHelper(currNode->m_left, aVal);
        }
        else
        {
            currNode->m_right = insertNodeHelper(currNode->m_right, aVal);
        }
    }

    return currNode;
}

void Tree::deleteNode(int aVal)
{
    if (m_root)
        m_root = deleteNodeHelper(m_root, aVal);
}

Node *Tree::deleteNodeHelper(Node *aCurrNode, int aVal)
{
    if (!aCurrNode)
    {
        return nullptr;
    }
    else if (aVal < aCurrNode->m_data)
    {
        aCurrNode->m_left = deleteNodeHelper(aCurrNode->m_left, aVal);
    }
    else if (aVal > aCurrNode->m_data)
    {
        aCurrNode->m_right = deleteNodeHelper(aCurrNode->m_right, aVal);
    }
    else
    {
        if (aCurrNode->m_left == nullptr &&
            aCurrNode->m_right == nullptr)
        {
            delete aCurrNode;
            return nullptr;
        }
        else if (aCurrNode->m_left != nullptr &&
                 aCurrNode->m_right == nullptr)
        {
            Node *leftSubTree = aCurrNode->m_left;
            delete aCurrNode;
            return leftSubTree;
        }
        else if (aCurrNode->m_left == nullptr &&
                 aCurrNode->m_right != nullptr)
        {
            Node *rightSubTree = aCurrNode->m_right;
            delete aCurrNode;
            return rightSubTree;
        }
        else
        {
            Node *successorNode = findSuccessor(aCurrNode->m_right);
            aCurrNode->m_data = successorNode->m_data;

            aCurrNode->m_right = deleteNodeHelper(aCurrNode->m_right, successorNode->m_data);
        }
    }
    return aCurrNode;
}

void Tree::viewInOrder()
{
    inOrderHelper(m_root);
}

void Tree::inOrderHelper(Node *currNode)
{
    if (currNode)
    {
        inOrderHelper(currNode->m_left);
        std::cout << currNode->m_data << " ";
        inOrderHelper(currNode->m_right);
    }
}

Node *Tree::findSuccessor(Node *aCurrNode)
{
    while (aCurrNode && aCurrNode->m_left)
    {
        aCurrNode = aCurrNode->m_left;
    }

    return aCurrNode;
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);

    tree.deleteNode(7);

    tree.viewInOrder();
    return 0;
}