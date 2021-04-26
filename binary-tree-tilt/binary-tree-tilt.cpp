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
    int findSum(TreeNode* root,int& tilt)
    {
        if(!root) return 0;
        int l = findSum(root->left,tilt);
        int r = findSum(root->right,tilt);
        tilt = tilt + abs(l - r);
        return l+r+root->val;
    }
    
    
public:
    int findTilt(TreeNode* root) {
        
        int tilt=0;
        findSum(root,tilt);
        return tilt;
        
    }
};
