/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <stack>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> outcome;

vector<int> rightSideView(TreeNode* root) {
    if (!root) return outcome;
    postOrder(root, 0);
    return outcome;
}

void postOrder(TreeNode* root, int depth=0) {
    if (depth == outcome.size()) outcome.push_back(root->val);
    depth++;
    if (root->right) postOrder(root->right, depth);
    if (root->left) postOrder(root->left, depth);
}


