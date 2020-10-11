#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        queue<tuple<TreeNode*, int>> q;
        q.push({root, 0});

        while (q.size() > 0) {
            auto [n, d] = q.front();
            q.pop();

            if (!n) continue;

            if (d > (int)result.size() - 1) {
                result.resize(d + 1);
            }
            result[d].push_back(n->val);

            q.push({n->left, d + 1});
            q.push({n->right, d + 1});
        }

        return result;
    }
};
