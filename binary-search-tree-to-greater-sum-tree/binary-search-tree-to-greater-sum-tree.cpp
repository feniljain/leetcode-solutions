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
    int transverse(TreeNode* root, int sum) {
         if(!root) {
            return sum;
        }
        
        sum = transverse(root->right, sum);
        cout<<sum<<" : "<<root->val<<" - ";
        sum+=root->val;
        root->val = sum;
        int suml = transverse(root->left, sum);
        cout<<sum<<" : "<<root->val<<endl;
        return suml;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
       transverse(root, 0);
       return root;
    }
};