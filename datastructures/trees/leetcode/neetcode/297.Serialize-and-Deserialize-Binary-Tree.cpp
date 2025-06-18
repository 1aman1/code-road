/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stringstream ss;

        encode(root, ss);
        return ss.str();
    }

    void encode(TreeNode *root, stringstream &ss)
    {
        if (root == nullptr)
        {
            ss << "NULL ";
            return;
        }

        ss << root->val << " ";

        encode(root->left, ss);
        encode(root->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        return decode(ss);
    }

    TreeNode *decode(stringstream &ss)
    {
        string currToken = "";
        ss >> currToken;

        if (currToken == "NULL")
        {
            return nullptr;
        }

        TreeNode *newNode = new TreeNode(stoi(currToken));
        newNode->left = decode(ss);
        newNode->right = decode(ss);

        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
