//{ Driver Code Starts
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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void find_par(Node* p,Node* root,int tar,map<Node*,Node*>&par,Node*& target){
        par[root]=p;
        if(root->data==tar){target=root;return;}
        if(root->left){find_par(root,root->left,tar,par,target);}
        if(root->right){find_par(root,root->right,tar,par,target);}
    }
    void bfs(map<Node*,Node*>&par,Node* cur,int&ans){
        queue<Node*> q;
        q.push(cur);
        map<Node*,int> vis;
        int lev=0;
        while(!q.empty()){
            int l=q.size();
            ans=max(ans,lev);
            while(l--){
                Node *t=q.front();q.pop();
                vis[t]=1;
                if(t->left && !vis[t->left]){q.push(t->left);}
                if(t->right && !vis[t->right]){q.push(t->right);}
                if(par[t]!=NULL && !vis[par[t]]){q.push(par[t]);}
            }
            lev++;
        }
    }
    int minTime(Node* root, int tar) 
    {
        map<Node*,Node*> par;
        Node *target;
        find_par(NULL,root,tar,par,target);
        int ans=0;
        bfs(par,target,ans);
        return ans;
    }
};

//{ Driver Code Starts.

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