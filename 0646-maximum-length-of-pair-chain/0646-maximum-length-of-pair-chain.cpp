class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),cmp);
        int ans=0,last=-1e9;
        for(int i=0;i<n;i++){
           if(a[i][0]>last){
               ans++;last=a[i][1];
           }
        }
        return ans;
    }
};