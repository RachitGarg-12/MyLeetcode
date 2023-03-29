class Solution {
bool isSafe(string s){
    int n = s.size();
    if(n>=4||n<=0)return false;
    if(n>1&&s[0]=='0')return false;
    if(n&&stoi(s)>255)return false;
    return true;
}
void solve(string s,vector<string>& ans,string st,int idx,int dot){
    if(dot==3){
        if(isSafe(s.substr(idx))){
            ans.push_back(st+s.substr(idx));
        }
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(isSafe(s.substr(idx,i-idx+1))){
            st.push_back(s[i]);
            st.push_back('.');
            solve(s,ans,st,i+1,dot+1);
            st.pop_back();
        }
        else{return;}
    }
}
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        string st = "";
        if(n<4)return ans;
        solve(s,ans,st,0,0);
        return ans;
    }
};