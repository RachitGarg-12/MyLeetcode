class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();int j=0;
        for(int i=0;i<m;i++){
            int t=a[0][i];int r=1,c=i+1;
            while(c<m && r<n){ if(a[r][c]!=t)return false;
                             r++;c++;}
        }
        for(int i=1;i<n;i++){
            int t=a[i][0];int r=i+1,c=1;
            while(r<n && c<m){
                 if(a[r][c]!=t)return false;
                             r++;c++;
            }
        }
        return true;
    }
};