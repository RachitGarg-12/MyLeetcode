class Solution {
public:
    vector<int> pre;
    int sum;
    Solution(vector<int>& w) {
        pre.push_back(w[0]);
        int n=w.size();
        for(int i=1;i<n;i++){
            pre.push_back(w[i]+pre.back());
        }
        sum=pre.back();
    }
    
    int pickIndex() {
        int num=rand()%sum;
        int ind=upper_bound(pre.begin(),pre.end(),num)-pre.begin();
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */