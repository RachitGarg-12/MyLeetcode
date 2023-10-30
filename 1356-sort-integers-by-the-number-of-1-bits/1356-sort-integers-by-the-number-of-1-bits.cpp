class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<20;j++){
                if(arr[i]&(1<<j)){cnt++;}
            }
            a[i]={cnt,arr[i]};
        }
        sort(a.begin(),a.end(),cmp);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=a[i].second;
        }
        return ans;
    }
};