class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        map<vector<int>,int> s;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++){
                temp.push_back(a[i][j]);
            }
            s[temp]++;
        }
        int ans=0;
        for(int j=0;j<m;j++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                temp.push_back(a[i][j]);
            }
            if(s[temp]){ans+=s[temp];}
        }
        return ans;
    }
};