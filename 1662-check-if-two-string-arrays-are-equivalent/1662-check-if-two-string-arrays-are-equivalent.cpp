class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string s1,s2;
        for(auto i:w1)s1+=i;
         for(auto i:w2)s2+=i;
        return s1==s2;
    }
};