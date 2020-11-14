/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 中序遍历当前结点的前一个结点，初始值当然是空结点
TreeNode* prev = nullptr;

bool isValidBST(TreeNode* root) {
    // 递归结束条件，即叶子节点默认返回true
    if (!root) return true;

    // 递归左子树，如果不是则返回false
    // 这里直接递归到了最左下角的结点，即不停访问左子树，直到第一个没有左子树的结点
    if (!isValidBST(root->left)) return false;

    // 比较当前结点和前一个结点val的大小，如果不严格递增，则返回false
    if (prev && root->val <= prev->val) return false;
    // 继续访问，前一个结点指向root，下一个要访问的结点是右子树的最左下方的结点
    prev = root;
    
    if (!isValidBST(root->right)) return false;
    return true;
}
