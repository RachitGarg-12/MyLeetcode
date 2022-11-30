class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m,n;
        for(auto i:arr){m[i]++;}
        int prev=m[arr[0]];bool b=false;
        for(auto i:m){
            n[i.second]++;
        }
        for(auto i:n){if(i.second>1)return false;}
        return true;
    }
};