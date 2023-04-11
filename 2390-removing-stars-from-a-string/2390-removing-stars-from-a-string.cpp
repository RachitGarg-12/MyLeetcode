class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(st.size()>0){st.pop();}
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};