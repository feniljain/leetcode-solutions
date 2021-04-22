/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<string>
class Codec {
public:

    // Encodes a tree to a single string.
    string s;
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }
        
        s+=to_string(root->val)+",";
        serialize(root->left);
        serialize(root->right);
        
        return s;
    }
    
    TreeNode* newNode(int val) {
        TreeNode* node = new TreeNode();
        node -> left = nullptr;
        node -> right = nullptr;
        node -> val = val;
        return node;
    }

    TreeNode* makeBST(vector<int> v, int start, int end) {
        if(start == end) return newNode(v[start]);
        if(start > end) return nullptr;
        
        int idx = end + 1;
        for(int i = start+1; i<=end ; i++) {
            if(v[start] < v[i]) {
                idx = i;
                break;
            }
        }
        TreeNode* root = newNode(v[start]);
        root->left = makeBST(v, start+1, idx-1);
        root->right = makeBST(v, idx, end);
        
        return root;
    }
    
    int strToInt(string s) {
        int rev = 0;
        for(int i = 0; i < s.length() ; i++) {
            rev = rev*10+(s[i]-'0');
        }
        
        return rev;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //cout<<data;
        vector<int> v;
        string str;
        for(int i = 0; i < data.length(); i++) {
            if(data[i]!=',') {
                str+=data[i];
            } else {
                cout<<str<< " : ";
                if(str != "") {
                 v.push_back(strToInt(str));   
                }
                str = "";
            }
        }
        
        return makeBST(v, 0, v.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;