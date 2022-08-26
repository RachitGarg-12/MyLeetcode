class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        if(s[0]=='0'){
            for(int i=1;i<n;i++){if(s[i]!='0'){swap(s[i],s[0]);break;}}
        }
        if(__builtin_popcount(stoi(s))==1) return true;
        while(next_permutation(s.begin(),s.end())){
            if(__builtin_popcount(stoi(s))==1) return true;
        }
        return false;
    }
};