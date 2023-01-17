class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int val=0,pow=1;
        int cnt=0;
        for(int i=n-1;i>=0 && val+pow<=k;i--){
            if(s[i]=='1'){
               val+=pow;
                cnt++;
            }
            pow<<=1;
        }
        
        return count(s.begin(),s.end(),'0')+cnt;
    }
};