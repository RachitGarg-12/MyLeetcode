class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto i:arr){m[i]++;}
        vector<int> freq;
        for(auto i:m){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        int l=freq.size();
        for(int i=0;i<l;i++){
            if(freq[i]>k){
                return l-i;
            }else{
                k-=freq[i];
            }
        }
        return 0;
    }
};