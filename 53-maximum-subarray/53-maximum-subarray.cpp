class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int prev=a[0];int ans=a[0];
        for(int i=1;i<n;i++){
            if(a[i]>prev && prev<=0){prev=a[i];}
            else{prev +=a[i];}
           ans=max(ans,prev);
        }
      
        return ans;
        
    }
};