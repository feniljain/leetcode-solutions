class Solution {
public:
    void check(TreeNode* root , vector<int> &v)
    {
        if(root==NULL)
            return;
        check(root->left,v);
        v.push_back(root->val);
        check(root->right,v);
    }
	
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> v1,v2,v; 
     if(root1==NULL && root2==NULL)
         return v;
        int i = 0 , j = 0;
		
        check(root1,v1);
        check(root2,v2);
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i] < v2[j])
            {
                v.push_back(v1[i]);
                i++;
            }
			
            else if(v1[i] > v2[j])
            {
                v.push_back(v2[j]);
                j++;
            } 
			
            else if(v1[i] == v2[j])
            {
                v.push_back(v1[i]);
                v.push_back(v2[j]);
                i++;
                j++;
            }
        }
        while(i < v1.size())
        {
             v.push_back(v1[i]);
                i++;
        }
            
        while(j< v2.size())
        {
            v.push_back(v2[j]);
                j++;
         }
        return v;
    }
};