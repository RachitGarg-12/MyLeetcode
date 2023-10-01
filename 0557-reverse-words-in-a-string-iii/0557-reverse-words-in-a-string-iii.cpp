class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans="";
        for(auto i:s){
            if(i==' '){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+=' ';
            }
            else{st.push(i);}
        }
       while(!st.empty()){
           ans+=st.top();
           st.pop();
        } 
        return ans;
    }
};