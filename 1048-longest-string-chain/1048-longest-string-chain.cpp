class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    bool cmp(string &a,string &b){
        if(a.size()!=b.size()+1){return false;}
        int i=0,j=0,dif=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[j]){i++;dif++;}
            else{i++;j++;}
            if(dif>1){return false;}
        }
        return true;
    }
    int longestStrChain(vector<string>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),comp);
        int mx=1;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(cmp(a[i],a[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};