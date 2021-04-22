/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* fn(ListNode* head,ListNode* tail)
    {
        if(head==NULL || tail==NULL)
        {
            return NULL;
        }
        if(head==tail)
        {
            return new TreeNode(head->val);
        }
        ListNode* fast=head->next;
        ListNode* mid=head;
        ListNode* prev=NULL;
        while(fast!=tail->next && fast->next!=tail->next)
        {
            fast=fast->next->next;
            prev=mid;
            mid=mid->next;
        }
        TreeNode* root=new TreeNode(mid->val);
        root->left=fn(head,prev);
        root->right=fn(mid->next,tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail=NULL;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            tail=tmp;
            tmp=tmp->next;
        }
        return fn(head,tail);
        
    }
};