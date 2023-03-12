class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int maximumBit) {
        int n=a.size();
        int prexor=0;
        for(int i=0;i<n;i++){
            prexor^=a[i];
        }
        vector<int> ans;
        int mx= (1<<maximumBit)-1;
        // for a1^a2^a3...^k=max , we have k= a1^a2^a3..^max
        // max is (2^maximumbit)-1
        for(int i=n-1;i>=0;i--){
            ans.push_back(prexor^mx);
            prexor^=a[i];
        }
        return ans;
    }
};