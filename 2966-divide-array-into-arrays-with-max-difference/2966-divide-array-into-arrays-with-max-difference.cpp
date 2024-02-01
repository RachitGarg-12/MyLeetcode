class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto i:nums){
            freq[i]++;
        }
        vector<vector<int>> ans;
        vector<int> cur;
        for(auto &i:freq){
            if(cur.size()>0){
                if(i.first-cur[0]>k){return {};}
                while(cur.size()<3 && i.second--){
                    cur.push_back(i.first);
                }      
                if(cur.size()==3){
                    ans.push_back(cur);
                    cur={};
                }              
            }
            while(i.second>=3){
                ans.push_back({i.first,i.first,i.first});
                i.second-=3;
            }
            if(i.second>0){
                while(i.second--){
                    cur.push_back(i.first);
                }
            }
        }
        return ans;
    }
};