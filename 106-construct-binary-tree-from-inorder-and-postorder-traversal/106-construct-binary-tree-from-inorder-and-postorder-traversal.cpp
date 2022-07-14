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
    unordered_map<int,int> inorderIndex;
    int postorderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            inorderIndex[inorder[i]]=i;
        }
        return arrToTree(postorder,0,postorder.size()-1);
    }
    TreeNode* arrToTree(vector<int> &postorder,int left,int right)
    {
        if(left>right)
            return NULL;
        int rootValue=postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root=new TreeNode(rootValue);
                              root->right=arrToTree(postorder,inorderIndex[rootValue]+1,right);

        root->left=arrToTree(postorder,left,inorderIndex[rootValue]-1);
        return root;
    }
};