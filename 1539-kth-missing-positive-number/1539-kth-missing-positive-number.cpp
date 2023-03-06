class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur=0,last=0;
        for(auto &i:arr){
            if(cur+i-last-1>=k){
                return last+k-cur;
            }
            else{
                cur+=i-last-1;last=i;
            }
        }
        return last+k-cur;
    }
};