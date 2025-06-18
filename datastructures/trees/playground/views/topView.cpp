#include <iostream>
#include <memory>
#include <queue>
#include <map>

using namespace std;

struct Node
{
    int m_data;
    int m_distance;
    unique_ptr<Node> m_left;
    unique_ptr<Node> m_right;

    Node(int val) : m_data(val),
                    m_distance(0),
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
    void topView();

private:
    NodePtr insertNodeHelper(NodePtr aCurrNode, int aVal);
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

void Tree::topView()
{
    if (not m_root)
        return;

    map<int, int> distToNode;
    queue<Node *> q;

    Node *currNode = m_root.get();
    int distance = 0;

    q.push(currNode);

    while (not q.empty())
    {
        currNode = q.front();
        q.pop();
        distance = currNode->m_distance;

        if (not distToNode.count(currNode->m_distance))
            distToNode[currNode->m_distance] = currNode->m_data;

        if (currNode->m_left)
        {
            currNode->m_left->m_distance = distance - 1;
            q.push(currNode->m_left.get());
        }
        if (currNode->m_right)
        {
            currNode->m_right->m_distance = distance + 1;
            q.push(currNode->m_right.get());
        }
    }

    for (const auto &eachPair : distToNode)
    {
        std::cout << eachPair.second << " ";
    }
}

int main()
{
    cout << "Building " << __FILE__ << endl;

    Tree tree;

    tree.insertNode(7);
    tree.insertNode(4);
    tree.insertNode(14);
    tree.insertNode(2);
    tree.insertNode(5);
    tree.insertNode(10);
    tree.insertNode(20);

    tree.topView();

    return 0;
}
