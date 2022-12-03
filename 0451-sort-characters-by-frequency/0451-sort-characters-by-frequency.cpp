class Solution {
public:
    string frequencySort(string s) {
       int n=s.size();map<char,int> m;vector<pair<int,int>> v;
       for(auto i:s){m[i]++;}
       int j=n-1;
       for(auto i:m){
           v.push_back({i.second,i.first});
       }
        sort(v.begin(),v.end());
        for(auto i:v){
            while(i.first--){s[j]=i.second;j--;}
        }
        return s;
    }
};