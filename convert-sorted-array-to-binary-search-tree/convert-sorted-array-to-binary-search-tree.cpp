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
    
    TreeNode* a(vector<int>& nums, int start, int end) {
        if(start == end) {
            return nullptr;
        }
        
        int mid = (int)((start+end)/2);
        //cout<<start<< "" << end << endl;
        cout<<nums[mid]<<endl;
        
        TreeNode* node = newNode(nums[mid]);
        
        node -> left = a(nums, start, mid);
        //a(nums, start, mid);
        //a(nums, mid+1, end);
        node -> right = a(nums, mid+1, end);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return a(nums, 0, nums.size());
    }
};