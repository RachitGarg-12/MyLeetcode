class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        set<int> s;
        map<int,vector<pair<int,int>>> pos;
        vector<int> row(n,0);//max till now in ith row
        vector<int> col(m,0);//max till now in ith col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pos[-mat[i][j]].push_back({i,j});
                s.insert(-mat[i][j]);
            }
        }
        for(auto ele:s){
            vector<vector<int>> equalval;
            for(auto cur:pos[ele]){
                int i=cur.first,j=cur.second;
                equalval.push_back({1+max(row[i],col[j]),i,j});
            }
            for(auto val:equalval){
                int ans=val[0],i=val[1],j=val[2];
                row[i]=max(row[i],ans);
                col[j]=max(col[j],ans);
            }
        }
        int ans=0;
        for(auto i:row){ans=max(ans,i);}
        for(auto i:col){ans=max(ans,i);}
        return ans;
    }
};