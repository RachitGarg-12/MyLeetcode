class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long ans=0;
        long long st=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]==0){
                st++;
                if(i==n-1){ans += (long long)(st*(long long)(st+1))/2;}
            }
            else if(st>0){
                ans += (long long)(st*(st+1))/2;
                st=0;
            }
            
        }
        
        return ans;
    }
};