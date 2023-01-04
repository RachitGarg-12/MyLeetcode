class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int p=(1<<n);
        for(int i=0; i<p; i++){
            v.push_back(i^(i/2));
        }
        return v;
    }
};