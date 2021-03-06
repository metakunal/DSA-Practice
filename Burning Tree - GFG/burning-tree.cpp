// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* createMapping(Node* root,int target,map<Node*,Node*> &mp)
  {
      queue<Node*> q;
      q.push(root);
      mp[root]=NULL;
      Node* res=NULL;
      while(q.empty()==false)
      {
          Node* top=q.front();
          q.pop();
          if(top->data==target)
            res=top;
          if(top->left!=NULL)
          {
                          mp[top->left]=top;
                          q.push(top->left);
          }

            
        if(top->right!=NULL)
        {
            mp[top->right]=top;
            q.push(top->right);
        }
      }
      return res;
  }
  int burnTree(Node* root,map<Node*,Node*> &childToParent)
  {
      map<Node*,bool> visited;
      queue<Node*> q;
      
      q.push(root);
      visited[root]=true;
      
      int ans=0;
      
      while(q.empty()==false)
      {
          bool flag=false;
          int size=q.size();
          for(int i=0;i<size;i++)
          {
              Node* top=q.front();
          q.pop();
          
          if(top->left!=NULL && !visited[top->left])
          {
              visited[top->left]=1;
              q.push(top->left);
              flag=true;
          }
          
          if(top->right!=NULL && !visited[top->right])
          {
              visited[top->right]=1;
              q.push(top->right);
              flag=true;
          }
          
          if(childToParent[top] && !visited[childToParent[top]])
          {
              visited[childToParent[top]]=1;
              q.push(childToParent[top]);
              flag=true;
          }
         
          }
           if(flag)
            ans++;
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> childToParent;
        Node* targetNode=createMapping(root,target,childToParent);
        int ans=burnTree(targetNode,childToParent);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends