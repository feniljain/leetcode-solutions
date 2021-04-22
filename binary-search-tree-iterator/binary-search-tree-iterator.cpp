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
class BSTIterator {
    private:
    stack<TreeNode*> st; // this stack will always hold atmost height of the tree
    void populateLeftSide(TreeNode* root){ // populate left subtree of the root
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*>();
        populateLeftSide(root); // init with left subtree of the root
    }
    
    int next() {
        TreeNode* top = st.top(); st.pop(); // top element will be returned
        if(top->right){ // if there exists a right subtree of the top element, populate in the stack
            populateLeftSide(top->right);
        }
        
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty(); // simply return if the stack is non-empty
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */