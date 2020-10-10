#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void serialize_impl(TreeNode* root, string& result) {
        if (root == nullptr) return;

        result.append(to_string(root->val));
        result.push_back(' ');

        serialize_impl(root->left, result);
        serialize_impl(root->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serialize_impl(root, result);
        return result;
    }

    void insert(TreeNode* root, int val) {
        if (val < root->val) {
            if (root->left == nullptr) {
                TreeNode* n = new TreeNode(val);
                root->left = n;
            } else {
                insert(root->left, val);
            }
        } else {
            if (root->right == nullptr) {
                TreeNode* n = new TreeNode(val);
                root->right = n;
            } else {
                insert(root->right, val);
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        TreeNode* root = nullptr;
        int val;
        while (s >> val) {
            if (root == nullptr) {
                root = new TreeNode(val);
            } else {
                insert(root, val);
            }
        }

        return root;
    }
};

int main(int argc, char const *argv[])
{
    auto root = new TreeNode(6);
    root->left = new TreeNode(3);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(4);

    root->right = new TreeNode(8);

    root->right->right = new TreeNode(9);

    Codec* ser = new Codec();
    Codec* deser = new Codec();

    string tree = ser->serialize(root);
    cout << tree << endl;

    TreeNode* ans = deser->deserialize(tree);

    string ans_tree = ser->serialize(ans);
    cout << tree << endl;

    // TODO: Delete trees
    // TODO: check ans and root for equality
}
