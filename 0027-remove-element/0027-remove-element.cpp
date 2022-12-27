class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),k=n;
        for(int i=0;i<k;i++){
            if(nums[i]==val){
                int dif=0;
                for(int j=i;j<k;j++){
                    while(j+dif<n && nums[j+dif]==val){dif++;k--;}
                    if(j+dif>=n){break;}
                    nums[j]=nums[j+dif];
                }
               break;
            }
        }
        return k;
    }
};