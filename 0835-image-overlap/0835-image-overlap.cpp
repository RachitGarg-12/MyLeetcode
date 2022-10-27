class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
              int n=img1.size();
        vector<pair<int,int>>vp1,vp2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    vp1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    vp2.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto it1:vp1){
            for(auto it2:vp2){
                int a=it1.first-it2.first;
                int b=it1.second-it2.second;
                mp[{a,b}]++;
                ans=max(ans,mp[{a,b}]);
            }
        }
        return ans;
    }
};