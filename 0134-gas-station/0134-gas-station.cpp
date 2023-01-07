class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tot=0;
        int ans=0,cur=0;
        for(int i=0;i<n;i++){
            int dif=gas[i]-cost[i];
            tot+=dif;
            cur+=dif;
            if(cur<0){
                ans=i+1;
                cur=0;
            }
        }
        if(tot<0)return -1;
        return ans;
    }
};