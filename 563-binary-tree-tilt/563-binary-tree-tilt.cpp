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
    vector<int> res;
    
    int helper(TreeNode *root)
    {
        int sum=0;
        if(root==NULL)
            return 0;
        if(root->left==NULL&&root->right==NULL)
            return root->val;
//         sum+=helper(root->left);
//         sum+=helper(root->right);
        sum+=((root->val)+helper(root->left)+helper(root->right));   
        return sum;
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        int sum1,sum2;
        sum1=helper(root->left);
        sum2=helper(root->right);
        res.push_back(abs(sum1-sum2));
        inorder(root->right);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 0;
        inorder(root);
        int ans=0;
        for(auto r:res)
        {
            cout<<r<<" ";
            ans+=r;
        }
        return ans;
        
        
    }
};