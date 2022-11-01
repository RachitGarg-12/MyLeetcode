class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();int r=0,w=0,b=0;
        for(auto i:nums){
            if(i==0){r++;}
            else if(i==1){w++;}
            else{b++;}
        }
        int i=0;
        while(r--){nums[i]=0;i++;}
        while(w--){nums[i]=1;i++;}
        while(b--){nums[i]=2;i++;}
    }
};