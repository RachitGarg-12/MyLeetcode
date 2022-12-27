class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        for(int i=0;i<n;i++){
            rocks[i]=capacity[i]-rocks[i];
        }
        int ans=0;
        sort(rocks.begin(),rocks.end());
        int cur=0;
        for(auto i:rocks){
            cur+=i;
            if(cur>additionalRocks)break;
            ans++;
        }
        return ans;
    }
};