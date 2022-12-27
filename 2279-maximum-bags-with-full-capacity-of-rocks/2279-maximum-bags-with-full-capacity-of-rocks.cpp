class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        map<int,int> m;
        for(int i=0;i<n;i++){m[capacity[i]-rocks[i]]++;}
        int ans=0;
        for(auto i:m){
            if(additionalRocks>i.first*i.second){
                additionalRocks -= i.first*i.second;
                ans+=i.second;
            }else{
                ans += additionalRocks/i.first;
                additionalRocks=0; 
                break;
            }
        }
        return ans;
    }
};