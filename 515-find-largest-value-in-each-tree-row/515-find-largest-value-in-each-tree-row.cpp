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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
          if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int s=q.size();
            int temp=INT_MIN;
            for(int i=0;i<s;i++)
            {
                TreeNode* top=q.front();
                temp=max(temp,top->val);
                q.pop();
                if(top->left!=NULL)
                    q.push(top->left);
                if(top->right!=NULL)
                    q.push(top->right);
            }
            res.push_back(temp);
        }
        return res;

    }
};