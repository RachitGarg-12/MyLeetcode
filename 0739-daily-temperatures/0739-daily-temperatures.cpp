class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();vector<int> ans(n,0);
        stack<pair<int,int>> s;s.push({t[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && t[i]>=s.top().first){
                s.pop();
            }
            if(!s.empty()){ans[i]=s.top().second-i;}
            s.push({t[i],i});
        }
        return ans;     
    }
};