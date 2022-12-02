class Solution {
public:
    bool closeStrings(string w1, string w2) {
                vector<int> f1(26), f2(26);
        for (char c : w1) ++f1[c-'a'];
        for (char c : w2) ++f2[c-'a'];
        
        return multiset(f1.begin(),f1.end()) == multiset(f2.begin(),f2.end()) &&
               unordered_set(w1.begin(),w1.end()) == unordered_set(w2.begin(),w2.end());
    }
};