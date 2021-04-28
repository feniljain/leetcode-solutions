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
    TreeNode* newNode(int val) {
        TreeNode* node = new TreeNode();
        node -> left = nullptr;
        node -> right = nullptr;
        node -> val = val;
        return node;
    }
    
    TreeNode* construct(vector<int>&nums, int start, int end) {
        if(start > end) return nullptr;
        
        int idx = 0, mx = INT_MIN;
        for(int i = start; i <= end; i++) {
            if(nums[i] > mx) {
                idx = i;
                mx = nums[i];
            }
        }
        //int idx = (start + end)/2;
        cout<<nums[idx]<<endl;
        
        TreeNode* root = newNode(nums[idx]);
        
        root -> left = construct(nums, start, idx - 1);
        root -> right = construct(nums, idx + 1, end);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};