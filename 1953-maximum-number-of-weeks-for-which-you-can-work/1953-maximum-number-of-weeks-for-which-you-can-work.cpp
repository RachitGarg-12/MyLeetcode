class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0;
        int mx=0;
        for(auto i:milestones){
            sum+=i;mx=max(mx,i);
        }
        long long rest=sum-mx;
        if(mx>rest){return 2*rest+1;}
        return sum;
    }
};