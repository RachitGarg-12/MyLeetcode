class Solution {
public:
bool pal(string S){ for (int i = 0;i <S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) { return false; }}
    return true;
}

vector<vector<string>> ans;
void rec(string s,vector<string> cur){
    int n=s.size();
    if(n==0){ans.push_back(cur);return;}
    
    string res="";
    for(int i=0;i<n;i++){
        res += s[i];
        if(pal(res)){
            string temp=s.substr(i+1,n-(i+1));
            cur.push_back(res);rec(temp,cur);
            cur.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        rec(s,cur);
        return ans;
    }
};