class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> dif(n);
        int d=0;
        for(int i=0;i<n;i++){
            dif[i]=gas[i]-cost[i];
            d+=dif[i];
        }
        if(d<0)return -1;
        if(n==1){return 0;}
        int ans=0,cur=0;
        for(int i=0;i<n;i++){
            cur+=dif[i];
            if(cur<0){
                ans=i+1;
                cur=0;
            }
        }
        return ans;
    }
};