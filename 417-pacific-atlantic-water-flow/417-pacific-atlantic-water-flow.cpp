class Solution {
public:
     int n,m;
    void dfs(vector<vector<int>>& heights,vector<vector<int>> &a,int i,int j){
        a[i][j]=1;
        
        if(i>0 && !a[i-1][j] && heights[i-1][j]>=heights[i][j]){ dfs(heights,a,i-1,j);}
        if(j>0 && !a[i][j-1] && heights[i][j-1]>=heights[i][j]){ dfs(heights,a,i,j-1);}
        if(i<n-1 && !a[i+1][j] && heights[i+1][j]>=heights[i][j]){ dfs(heights,a,i+1,j);}
        if(j<m-1 && !a[i][j+1] && heights[i][j+1]>=heights[i][j]){ dfs(heights,a,i,j+1);}
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();m=heights[0].size();
        vector<vector<int>> a(n,vector<int>(m,0));
        vector<vector<int>> b(n,vector<int>(m,0));
      
        for(int i=0;i<n;i++){dfs(heights,a,i,0);}
        for(int i=1;i<m;i++){dfs(heights,a,0,i);}
        for(int i=0;i<n;i++){dfs(heights,b,i,m-1);}
        for(int i=0;i<m-1;i++){dfs(heights,b,n-1,i);}
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && b[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};