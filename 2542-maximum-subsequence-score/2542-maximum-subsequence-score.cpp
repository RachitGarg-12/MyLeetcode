class Solution {
public:
    int n;
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        n=a.size();
        long long add=0;
        vector<pair<int,int>> both;
        for(int i=0;i<n;i++){
            both.push_back({b[i],a[i]});
        }
        sort(both.begin(),both.end());
        priority_queue<int, vector<int>, greater<int>> pr;
        for(int i=n-1;i>=n-k;i--){
            pr.push({both[i].second});
            add+=both[i].second;
        }
        long long ans = add*both[n-k].first;
        for(int i=n-k-1;i>=0;i--){
            pr.push(both[i].second);
            add-=pr.top();
            add+=both[i].second;
            pr.pop();
            ans=max(both[i].first*add,ans);
        }
        return ans;
    }
};