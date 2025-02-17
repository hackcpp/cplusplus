/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    
        if (!root) return {};

        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* last = nullptr;
        
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            TreeNode* node = st.top();
            if (node->right && node->right != last) {
                root = node->right;
            } else {
                res.push_back(node->val);
                last = node;
                st.pop();
            }
        }
        return res;
    }
};
// @lc code=end
