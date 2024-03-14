class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> one;
        one.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]==1){one.push_back(i);}
        }
        one.push_back(n);
        int l=one.size();
        int ans=0;
        if(goal==0){
            for(int i=1;i<l;i++){
                int zero=one[i]-one[i-1]-1;
                ans += (zero * (zero+1))/2;
            }
            return ans;
        }
        for(int i=goal;i<l-1;i++){
            int st=i-goal+1;
            int forzero = one[st]-one[st-1]-1;
            int baczero = one[i+1]-one[i]-1;
            ans++;
            if(forzero==0){ans+=baczero;}
            else if(baczero==0){ans+=forzero;}
            else{
                ans+=forzero*baczero;
                ans+=baczero+forzero;
            }
        }
        return ans;
    }
};