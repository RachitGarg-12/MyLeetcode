class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size(); unordered_map<int,int> m;
        for(int i:arr){m[i]++;}
        int rem=0;int curr=0;
        vector<pair<int,int>> A;
        for (auto& it : m) {
            cout<<it.first<<" "<<it.second<<endl;
        A.push_back({it.second,it.first});}
        sort(A.begin(), A.end());
        for(int i=A.size()-1;i>=0;i--){
            cout<<curr<<" "<<A[i].first<<endl;
            if(curr<n/2){curr += A[i].first;rem++;}
            else{break;}
        }
        return rem;
    }
};