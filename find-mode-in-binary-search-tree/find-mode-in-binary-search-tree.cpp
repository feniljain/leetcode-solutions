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
    map<int, int> mp;
    int max = INT_MIN;
    void transverse(TreeNode* root) {
        if(!root) {
            return;
        }
        
        transverse(root->left);
        if(mp.count(root->val) == 0) {
            mp[root->val] = 1;
        } else {
            mp.at(root->val) = mp[root->val]+1;
        }
        if(mp[root->val] > max) {
                max = mp[root->val];
            }
        transverse(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        
        transverse(root);
        
        for(auto itr: mp) {
            if(itr.second == max) {
                v.push_back(itr.first);
            }
        }
        return v;
    }
};