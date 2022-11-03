class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int n=f.size(),m=s.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<n && j<m){
            // cout<<i<<" "<<j<<endl;
            if(f[i][0]<=s[j][1] && s[j][0]<=f[i][1]){
                ans.push_back({max(f[i][0],s[j][0]),min(f[i][1],s[j][1])});
                if(f[i][1]<s[j][1]){i++;}
                else if(f[i][1]>s[j][1]){j++;}
                else{i++;j++;}
            }
            else if(f[i][1]<s[j][0]){i++;}
            else if(s[j][1]<f[i][0]){j++;}
            
        }
        return ans;
    }
};