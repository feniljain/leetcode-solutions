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
    int min = INT_MAX;
    TreeNode* preorderSuccessor(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        
        TreeNode* node =  preorderSuccessor(root->right);
        if(node == nullptr) {
            return root;
        } else {
            return node;
        }
    }
    TreeNode* postorderSuccessor(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        
        TreeNode* node =  postorderSuccessor(root->left);
        if(node == nullptr) {
            return root;
        } else {
            return node;
        }
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root) {
            return min;
        }
            TreeNode* prev = preorderSuccessor(root->left);
        if(prev) {
            cout<<root->val<<" - "<<prev->val<<endl;
         if(abs(root->val-prev->val) < min) {
            min = abs(root->val-prev->val);
         }
        }
            TreeNode* post = postorderSuccessor(root->right);
            
                if(post) {
                    cout<<root->val<<" : "<<post->val<<endl;
                    if(abs(root->val-post->val) < min) {
            min = abs(root->val-post->val);
         }
                }
        
        getMinimumDifference(root->left);
        getMinimumDifference(root->right);
        
        return min;
    }
};