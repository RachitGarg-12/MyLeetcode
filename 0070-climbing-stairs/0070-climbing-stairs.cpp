class Solution {
public:
    int climbStairs(int n) {
        int prev2=1,prev=1;
        int cur=1;
        for(int i=2;i<=n;i++){
            cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return cur;
    }
};