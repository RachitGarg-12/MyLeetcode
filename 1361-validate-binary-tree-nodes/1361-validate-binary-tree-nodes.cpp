class Solution {
public:
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(dfs(j,adj,vis,pathvis)){return true;}
            }
            else if(pathvis[j]){return true;}
        }
        pathvis[i]=0;
        return false;
        
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> freq(n,0),parent(n,-1);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                parent[leftChild[i]]=i;
                adj[i].push_back(leftChild[i]);
                freq[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                parent[rightChild[i]]=i;
                adj[i].push_back(rightChild[i]);
                freq[rightChild[i]]++;
            }
            if((leftChild[i] !=-1 && freq[leftChild[i]]>1)|| (rightChild[i]!=-1 && freq[rightChild[i]]>1)){return false;}
        }
        vector<int> vis(n,0),pathvis(n,0);
        if(dfs(0,adj,vis,pathvis)){return false;}
        int cnt=0;
        for(auto i:parent){
            if(i==-1){cnt++;}
        }
        return cnt==1;
    }
};