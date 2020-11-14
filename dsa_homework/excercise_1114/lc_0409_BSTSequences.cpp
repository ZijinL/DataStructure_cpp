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
#include <queue>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> res;

vector<vector<int>> BSTSequences(TreeNode* root) {
    if (!root) 
        return;
    vector<vector<int>> left = BSTSequences(root->left);
    vector<vector<int>> right = BSTSequences(root->right);

    for(vector<int> item_l: left) {
        for(vector<int> item_r: right) {
            item_l.insert(item_l.end(),item_r.begin(),item_r.end());

        }
    }
}


void permutation() {

}




