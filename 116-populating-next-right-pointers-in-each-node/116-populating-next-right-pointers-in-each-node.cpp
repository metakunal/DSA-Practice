/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> res;
          if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int s=q.size();
            vector<Node*> temp;
            for(int i=0;i<s;i++)
            {
                Node* top=q.front();
                temp.push_back(top);
                q.pop();
                if(top->left!=NULL)
                    q.push(top->left);
                if(top->right!=NULL)
                    q.push(top->right);
            }
            res.push_back(temp);
        }
        for(auto r:res)
        {
            for(int i=0;i<r.size();i++)
            {
                if(i==r.size()-1)
                    r[i]->next=NULL;
                else
                    r[i]->next=r[i+1];
            }
        }
        return root;
    }
};