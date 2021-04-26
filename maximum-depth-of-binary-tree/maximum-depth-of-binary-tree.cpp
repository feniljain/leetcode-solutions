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
    int max = 0;
    int maxDepth(TreeNode* root, int depth = 0) {
        if(!root) return max;
        
        depth++;
        if(depth > max) max = depth;
        
        maxDepth(root->left, depth);
        maxDepth(root->right, depth);
        return max;
    }
};