class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();multimap<int,int> v;
        for(int i=0;i<n;i++){
            v.insert(pair<int, int>(abs(x-arr[i]),arr[i]));
        }
        vector<int> ans;int it=0;
        for(auto i:v){
            ans.push_back(i.second);it++;
            if(it==k)break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};