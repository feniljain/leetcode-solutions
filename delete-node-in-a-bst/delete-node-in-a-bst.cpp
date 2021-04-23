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
    TreeNode* inorderSuccessor(TreeNode* root) {
        TreeNode *curr = root;
        
        while(curr && curr->left!=nullptr) {
            curr = curr->left;
        }
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val > key){ //go to the left if key is less than current node value
            root->left = deleteNode(root->left, key);
        } 
        else if(root->val < key){ //go to the right if key is more than current node value 
            root->right = deleteNode(root->right, key);
        }
        else{
            //when the target node is found 
            if(root->left == nullptr) return root->right;
            else if(root->right == nullptr) return root->left;
            else{
                TreeNode* parent = root;
                TreeNode* newNode = root->right;
                // find the most left node of the target node 
                while(newNode->left != nullptr){
                    parent = newNode;
                    newNode = newNode->left;
                } 
                //this is crucial, only when newNode has left child we do this manipulation  
                if(parent != root){
                    parent->left = newNode->right;
                    newNode->right = root->right;
                }
                newNode->left = root->left;
                delete root;
                return newNode;
            } 
        }
        return root;
    }
};