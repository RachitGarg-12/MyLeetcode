class Solution {
public:
    bool canJump(vector<int>& a) {
        int n=a.size();
        int maxreach=0;
        for(int i=0;i<n;i++){
            if(maxreach<i)return 0;
            maxreach=max(maxreach,i+a[i]);
        }
        return 1;
    }
};