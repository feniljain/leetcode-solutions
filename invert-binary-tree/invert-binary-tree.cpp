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
#include <bits/stdc++.h>
class Solution {
public:
    // Print the queue
void showq(queue<TreeNode*> gq)
{
    queue<TreeNode*> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front()->val;
        g.pop();
    }
    cout << '\n';
}
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};