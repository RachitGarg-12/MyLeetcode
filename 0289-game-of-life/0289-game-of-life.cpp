class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=0;
                //upper row neighbours
                if(i-1>=0){
                    if(j-1>=0){live+= a[i-1][j-1];}
                    live+=a[i-1][j];
                    if(j+1<m){live+=a[i-1][j+1];} }
                //same row neighbours
                if(j-1>=0){live+= a[i][j-1];}
                if(j+1<m){live+=a[i][j+1];}
                //down row neighbours
                if(i+1<n){
                    if(j-1>=0){live+= a[i+1][j-1];}
                    live+=a[i+1][j];
                    if(j+1<m){live+=a[i+1][j+1];} }
                
                if(a[i][j]==1){
                    if(live<2){ans[i][j]=0;}
                    else if(live==2 || live==3){ans[i][j]=1;}
                    else{ans[i][j]=0;}
                }else{
                    if(live==3){ans[i][j]=1;}
                    else{ans[i][j]=0;}
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){a[i][j]=ans[i][j];}}
    }
};