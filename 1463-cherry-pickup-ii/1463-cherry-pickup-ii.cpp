class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    int cherryPickup(vector<vector<int>>& a) {
        n=a.size();m=a[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j){dp[n-1][i][j]=a[n-1][i];}
                else{dp[n-1][i][j]=a[n-1][i]+a[n-1][j];}
            }    
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=0;
                  for(int k=-1;k<2;k++){
                    for(int j=-1;j<2;j++){ 
                      if(j1+k>=0 && j1+k<m && j2+j>=0 && j2+j<m){
                       if(j1==j2){maxi=max(maxi,a[i][j1]+dp[i+1][j1+k][j2+j]);}
                       else{
                        maxi=max(maxi,a[i][j1]+a[i][j2]+dp[i+1][j1+k][j2+j]);
                           }
                      }
                }
            }
               dp[i][j1][j2]=maxi;   
        }
      }
    }
        return dp[0][0][m-1];
    }
};