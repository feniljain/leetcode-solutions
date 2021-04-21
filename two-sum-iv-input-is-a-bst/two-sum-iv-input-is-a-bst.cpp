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
#include <stdio.h>
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s, rs;
        TreeNode *curr = root, *rcurr = root;
        while(curr!=NULL) {
                s.push(curr);
                curr = curr->left;
            }
        while(rcurr != NULL) {
                    
                    rs.push(rcurr);
            rcurr = rcurr -> right;
        }
        while(!s.empty() && !rs.empty()) {
                curr = s.top(); 
            
                rcurr = rs.top();
            
                // cout<<curr->val<<" : ";
                // cout<<rcurr->val<<endl;
            
                if(curr == rcurr) {
                    return false;
                }
            
                // if(curr->val == rcurr->val) {
                //     continue;
                // }
            
                if((curr->val+rcurr->val)>k) {
                    //rcurr = rs.top();
                    rs.pop();
                    rcurr = rcurr -> left;
                    while(rcurr!=NULL) {
                rs.push(rcurr);
                rcurr = rcurr->right;
            }
                } else if((curr->val+rcurr->val)<k) {
                    //curr = s.top();
                    s.pop();
                    curr = curr -> right;
                     while(curr != NULL) {
                    
                    s.push(curr);curr = curr -> left;
                }
                } else {
                    return true;
                }
        }
        //cout<<"Here";
        return false;
    }    
};