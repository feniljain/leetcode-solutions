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
    TreeNode* transverse(vector<int>& preorder, int start, int end) {
        //TreeNode* node = nullptr;
        // if(end-start == 2) {
        //         node -> left = newNode(preorder[start+1]);
        //         node -> right = newNode(preorder[start+2]);
        //     return node;
        // } else if(end-start == 1) {
        //     if(preorder[start + 1] < preorder[start]) {
        //         node -> left = newNode(preorder[start + 1]);
        //     } else {
        //         node -> right = newNode(preorder[start + 1]);
        //     }
        //     return node;
        // } else if(start == end) {
        //     return node;
        // }
        if(start == end) {
            //cout<<"Returning val: " << node->val<<endl;
            return newNode(preorder[start]);
        } else if(start > end) {
            return nullptr;
        }
        
        
        int mid = end+1;
        for(int i=start+1; i<=end; i++) {
            if(preorder[i] > preorder[start]) {
                cout<<"Match at i: " << i << " :: ";
                mid = i;
                break;
            }
        }
        
        TreeNode* node = newNode(preorder[start]);
//         if(mid == start) {
//             if(preorder[start] < preorder[start  + 1]) {
                
//                 node -> right = transverse(preorder, start + 1, end);
//             } else {
//                 node -> left = transverse();
//             }
//         }
        //cout<<mid
        cout<<start<<" - "<<end<<" - "<<mid<<endl;
        node -> left = transverse(preorder, start+1, mid-1);
        node -> right = transverse(preorder, mid, end);
        // transverse(preorder, start+1, mid);
        // transverse(preorder, mid+1, end);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return transverse(preorder, 0, preorder.size()-1);
    }
};