class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> a;
        for(auto i:points){
            int x1=i[0],y1=i[1];
            int dis=(x1*x1)+(y1*y1);
            a.push_back({dis,x1,y1});
        }
        sort(a.begin(),a.end());
        vector<vector<int>> ans(k);
        for(int i=0;i<k;i++){
            ans[i]={a[i][1],a[i][2]};
        }
        return ans;
    }
};