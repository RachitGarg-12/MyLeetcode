class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m;
        for(int x: nums) m[x]++;
        int a=0,b=0,c=0;
        for(int k=-1000; k<=1001; k++){
            if(m[k]<a+b) return false;
            int a_prev = a;
            a = max(0,m[k]-a-b-c);
            b = a_prev;
            c = m[k]-a-b;
        }
        return true;
    }
    
};