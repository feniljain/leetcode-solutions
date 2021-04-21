/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return lca;
        }
        
        TreeNode* temp;
        if(p -> val > q -> val) {
            temp = p;
            p = q;
            q= temp;
        }
        
        cout<<p->val << " : "<<q->val<< " - ";
        
        cout<< (root -> val >= p -> val && root->val <= q->val ) << " ' ";
        if(root -> val >= p -> val && root->val <= q->val) {
            cout<<root->val;
            lca = root;
            return lca;
        }
        
        if(root->val < p->val) {
            lowestCommonAncestor(root->right, p, q);
        } else if(root->val > q->val) {
            lowestCommonAncestor(root->left, p, q);
        }
        
        return lca;
    }
};