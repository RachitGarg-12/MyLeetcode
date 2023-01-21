class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=0;
        int lastsec=0,last=0;
        for(int i=2;i<=n;i++){
            ans=min(lastsec+cost[i-2],last+cost[i-1]);
            lastsec=last;last=ans;
        }
        return ans;        
    }
};