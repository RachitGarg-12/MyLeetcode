class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();string ans="";string word="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){reverse(word.begin(),word.end());ans+=word;ans+=s[i];word="";}
            else{word+=s[i];
                if(i==n-1){reverse(word.begin(),word.end());ans+=word;}}
        }
        return ans;
    }
};