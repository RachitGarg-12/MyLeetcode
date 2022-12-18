class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();vector<int> ans(n);
        stack<pair<int,int>> s;
        s.push({t[n-1],0});ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int dist=0,ex=0;
            while(!s.empty() && t[i]>=s.top().first){
                ex+=s.top().second;s.pop();dist++;
            }
            // cout<<i<<" "<<dist<<" "<<ex<<endl;
            if(s.empty()){ans[i]=0;s.push({t[i],0});}
            else{ans[i]=dist+ex+1;s.push({t[i],dist+ex});}
            
        }
        return ans;     
    }
};