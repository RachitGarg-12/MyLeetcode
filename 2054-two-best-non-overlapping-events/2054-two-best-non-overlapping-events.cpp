class Solution {
public:
	int f(int i,int count,vector<int>& st,vector<vector<int>>& eve,int n,vector<vector<int>>& dp){
		if(i>=n || count==2) return 0;
		if(dp[i][count]!=-1) return dp[i][count];
		int ind=upper_bound(st.begin(),st.end(),eve[i][1])-st.begin();
		int pick = eve[i][2] + f(ind,count+1,st,eve,n,dp);
		int notpick = f(i+1,count,st,eve,n,dp);
		return dp[i][count]=max(pick,notpick);
	}

	int maxTwoEvents(vector<vector<int>>& eve) {
		int n=eve.size();
		sort(eve.begin(),eve.end());
		vector<int> st;
		vector<vector<int>> dp(n,vector<int>(3,-1));
		for(auto i: eve) st.push_back(i[0]);
		return f(0,0,st,eve,n,dp);
	}
};