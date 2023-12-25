class Solution {
public:
    int numDecodings(string s) {
		int n=s.size();
		if(n==1){            // for length=1
			if(s[0]>'0') return 1;
			else return 0;
		}
		vector<int> dp(n);

		for(int i=n-1;i>=0;--i){
			if(s[i]>'0'){
				dp[i]=(i+1<n)? dp[i+1]:1;
				if(i+1<n && (s[i]=='1' || (s[i]<='2' && s[i+1]<='6'))){
					 // if i=1 then i-1 can be from 0 to 9 OR i=2 then i-1 should be from 0 to 6
					dp[i]+=(i+2<n)? dp[i+2]:1;
				}
			}
		}
		return dp[0];
    }
};