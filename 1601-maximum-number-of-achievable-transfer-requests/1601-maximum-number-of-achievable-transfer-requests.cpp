class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& a) {
        int N = (int)a.size();
        int ans = 0;
        for(int i = 0 ; i < (1 << N) ; i++) {
            int setbits = 0;
            vector<int>cnt(n,0);
            for(int j = 0 ; j < N ; j++) {
                if(((1 << j) & (i))) {
                    ++setbits;
                    cnt[a[j][0]]--;
                    cnt[a[j][1]]++;
                }
            }
            bool ok = 1;
            for(int j = 0 ; j < n ; j++) {
                if(cnt[j] != 0) ok = 0;
            }
            if(ok) {
                ans = max(ans,setbits);
            }
        }
        return ans;
    }
};