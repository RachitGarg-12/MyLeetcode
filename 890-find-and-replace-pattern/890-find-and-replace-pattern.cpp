class Solution {
public:
    string same(string w){
        map<char, char> m;char st='a';
        for (char c : w){if (!m.count(c)) m[c] = st++;}
       for(auto& i:w){i=m[i];}
        return w;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string> ans;
        string s=same(pattern);
        for(auto i:words){
            if(same(i)==s){ans.push_back(i);}
        }
        return ans;
    }
};