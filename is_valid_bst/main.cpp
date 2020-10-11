#include <vector>
#include <iostream>
#include <optional>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {}
};

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& ns) {
        if (!root) return;
        inOrder(root->left, ns);
        ns.push_back(root->val);
        inOrder(root->right, ns);
    }

    bool isValidBST_inOrder(TreeNode* root) {
        if (!root) return true;
        vector<int> ns;
        inOrder(root, ns);
        for (int i = 0; i < (int)ns.size() - 1; i++) {
            if (ns[i] >= ns[i + 1]) return false;
        }

        return true;
    }

    // ---

    bool checkBounds(
        TreeNode* root,
        optional<int> low,
        optional<int> high
    ) {
        if (!root) return true;
        if (low.has_value() && root->val <= *low) return false;
        if (high.has_value() && root->val >= *high) return false;

        return
            checkBounds(root->left, low, make_optional(root->val)) &&
            checkBounds(root->right, make_optional(root->val), high);
    }

    bool isValidBST_bounds(TreeNode* root) {
        return checkBounds(root, nullopt, nullopt);
    }

    // ---

    bool isValidBST_iter_inorder(TreeNode* root) {
        stack<TreeNode*> s;
        optional<int> prev_val;

        while (s.size() > 0 || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            if (prev_val.has_value() && root->val <= *prev_val) return false;
            prev_val = make_optional(root->val);
            root = root->right;
        }

        return true;
    }
};
