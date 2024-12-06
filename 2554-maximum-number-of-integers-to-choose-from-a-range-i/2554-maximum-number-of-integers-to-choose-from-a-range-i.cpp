class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,bool> mp;
        for(auto i:banned){
            mp[i]=true;
        }
        int cursum=0,ans=0;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                if(cursum+i<=maxSum){
                    cursum+=i;
                    ans++;
                }
                else{break;}
            }
        }
        return ans;
    }
};