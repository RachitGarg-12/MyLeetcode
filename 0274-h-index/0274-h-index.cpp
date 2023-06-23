class Solution {
public:
    int hIndex(vector<int>& citations) {
     int n = citations.size();  
      vector<int> dp(n+1,0); //number of citations with val > i
      for(int i=0;i<n;i++){
          if(citations[i] > n) dp[n]++; 
          else dp[citations[i]]++;
      }
      int sum=0;
      for(int i=n;i>=0;i--){
          sum+=dp[i];
          if(i <= sum)
            return i;
      }
      return -1;        
    }
};