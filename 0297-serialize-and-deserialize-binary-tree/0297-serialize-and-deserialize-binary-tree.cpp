/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){return "";}
        string serial="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur=q.front();q.pop();
            if(cur==NULL){serial+='#';serial+=',';continue;}
            else{serial+=to_string(cur->val)+',';}
            q.push(cur->left);
            q.push(cur->right);
        }
        serial.pop_back();
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){return NULL;}
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root= new TreeNode(stoi(str)); 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){node->left=NULL;}
            else{
                TreeNode *leftnode= new TreeNode(stoi(str));
                node->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){node->right=NULL;}
            else{
                TreeNode *rightnode= new TreeNode(stoi(str));
                node->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));