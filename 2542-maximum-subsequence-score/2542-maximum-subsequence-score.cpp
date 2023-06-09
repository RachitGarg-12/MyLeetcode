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
        sort(both.rbegin(),both.rend());
        priority_queue<int, vector<int>, greater<int>> pr;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(pr.size()>=k){
               add-=pr.top();
               pr.pop();
            }
            pr.push(both[i].second);
            add+=both[i].second;
            if(pr.size()==k){
                ans=max(ans,(long long)both[i].first*add);
            }
        }
        return ans;
    }
};