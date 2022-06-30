/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findpath(TreeNode* root,vector<TreeNode*> &path,TreeNode* n)
    {
        if(root==NULL)
            return false;
        path.push_back(root);
        if(root->val==n->val)
            return true;
        if(findpath(root->left,path,n)||findpath(root->right,path,n))
            return true;
        
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;
        findpath(root,path1,p);
        findpath(root,path2,q);
        int n=min(path1.size(),path2.size());
        // cout<<path1.size();
       for (int i=1; i<n; i++) {
            if (path1[i]!=path2[i]) return path1[i-1];
        }
        return path1[n-1];
    }
};