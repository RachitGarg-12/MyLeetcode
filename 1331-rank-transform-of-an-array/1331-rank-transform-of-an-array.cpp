class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> b=arr;
        sort(b.begin(),b.end());
        map<int,int> mp;
        int cur=0,last=-1;
        for(auto i:b){
            if(i!=last){
                mp[i]= ++cur;
            }else{
                mp[i]=cur;
            }
            last=i;
        }
        vector<int> rank;
        for(auto i:arr){

            rank.push_back(mp[i]);
        }
        return rank;
    }
};