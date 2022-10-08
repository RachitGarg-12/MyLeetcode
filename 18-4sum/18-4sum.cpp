class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        if(a.size()<4){return {};}
        sort(a.begin(),a.end());
        int n=a.size();map<vector<int>,int> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(long)a[i]+a[j]+a[l]+a[r];
                    if(sum==t){ans[{a[i],a[j],a[l],a[r]}]++;l++;r--;}
                    else if(sum<t){l++;}
                    else{r--;}
                }
            }
        }
        vector<vector<int>> res;int l=ans.size();
        for(auto i:ans){res.push_back(i.first);}
        return res;
    }
};