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
    vector<int> nums;
    
    void transverse(TreeNode* root) {
        if(!root) return;
        
        transverse(root->left);
        nums.push_back(root->val);
        transverse(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        transverse(root);
        
        for(int i=0; i<nums.size()-1; i++) {
                if(nums[i]>=nums[i+1]) {
                    return false;
                }
        }
        
        return true;
    }
};