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
    int val = INT_MIN;
    bool unival = true;
    bool isUnivalTree(TreeNode* root) {
        if(!root) return unival;
        
        if(val == INT_MIN) val = root->val;
        
        if(val != root->val) unival = false;
        
        isUnivalTree(root->left);
        isUnivalTree(root->right);
        
        return unival;
    }
};