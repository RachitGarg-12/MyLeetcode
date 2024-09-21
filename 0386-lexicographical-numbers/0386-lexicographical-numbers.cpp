class Solution {
public:
    static bool cmp(int a,int b){
        string aa=to_string(a), bb=to_string(b);
        return aa<bb;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};