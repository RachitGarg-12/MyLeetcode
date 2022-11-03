class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,-1));
        bool rf=true,cd=false,rb=false,cu=false;
        int cur=1;
        for(int i=0;i<n;i++){ans[0][i]=cur;cur++;}
        for(int i=1;i<n;i++){ans[i][n-1]=cur;cur++;}
        if(n-1!=0){for(int i=n-2;i>=0;i--){ans[n-1][i]=cur;cur++;}}
        if(n-1!=0){for(int i=n-2;i>0;i--){ans[i][0]=cur;cur++;}}
        int i=1,j=1;
        if(i>=n || j>=n){ return ans;}
        
        while(ans[i][j]==-1){
            if(rf==true){
                if(ans[i][j]!=-1){break;}
                for(int k=j;k<n;k++){
                    if(ans[i][k]!=-1){i++;j=k-1;cd=true;rf=false;break;}
                    ans[i][k]=cur;cur++;
                }
            }
            if(cd==true){
                if(ans[i][j]!=-1){break;}
                for(int k=i;k<n;k++){
                    if(ans[k][j]!=-1){j--;i=k-1;rb=true;cd=false;break;}
                    ans[k][j]=cur;cur++;
                }
            }
            if(rb==true){
                if(ans[i][j]!=-1){break;}
                for(int k=j;k>=0;k--){
                    if(ans[i][k]!=-1){i--;j=k+1;cu=true;rb=false;break;}
                    ans[i][k]=cur;cur++;
                }
            }
            if(cu==true){
                if(ans[i][j]!=-1){break;}
                for(int k=i;k>=0;k--){
                    if(ans[k][j]!=-1){j++;i=k+1;rf=true;cu=false;break;}
                    ans[k][j]=cur;cur++;
                }
            }
            
        }
        return ans;
    }
};