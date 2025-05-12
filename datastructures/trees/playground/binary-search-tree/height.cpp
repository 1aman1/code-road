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

    void viewInOrder();
    int height();

private:
    NodePtr insertNodeHelper(NodePtr aCurrNode, int aVal);

    void inOrderHelper(Node *aCurrNode);
    int heightHelper(Node *);
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

int Tree::height()
{
    if (m_root)
        return heightHelper(m_root.get());
}

int Tree::heightHelper(Node *aCurrNode)
{
    if (aCurrNode == nullptr)
        return 0;

    int leftSubTreeHeight = heightHelper(aCurrNode->m_left.get());
    int rightSubTreeHeight = heightHelper(aCurrNode->m_right.get());

    return (leftSubTreeHeight > rightSubTreeHeight ? leftSubTreeHeight : rightSubTreeHeight) + 1;
}

int main()
{
    cout << "Building " << __FILE__ << endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);

    tree.viewInOrder();
    std::cout << "height " << tree.height();

    return 0;
}
