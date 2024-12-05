class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto i:arr){
            if(mp.find(i*2)!=mp.end() || (i%2==0 && mp.find(i/2)!=mp.end()))return true;
            mp[i]++;
        }
        return false;
    }
};