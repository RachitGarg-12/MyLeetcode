class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int i=0;i<=31;i++){
            int first=((1<<i)&start);
            int sec=((1<<i)&goal);
            // cout<<first<<" "<<sec<<endl;
            if(first!=sec)ans++;
        }
        return ans;
    }
};