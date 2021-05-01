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
    int convert(TreeNode* root) {
        if(!root) return 0;
        
        int cnt = 0;
        if(root->val == 1) {
            cnt = 1;
        }
        
        int lCnt = convert(root->left);
        if(!lCnt) {
            root->left = nullptr;
        }
        int rCnt = convert(root->right);
        if(!rCnt) {
            root->right = nullptr;
        }
        
        if(lCnt) {
            cout<<"l "<<root->val<<endl;
        }
        if(rCnt) {
            cout<<"r "<<root->val<<endl;
        }
        
        return lCnt + rCnt + cnt;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int cnt = convert(root);
        if(cnt == 0) {
            return nullptr;
        }
        return root;
    }
};