class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        //nearest smallest element on right
        stack<int> st;
        st.push(-1);
        vector<int> ans(a.size());
        
        for(int i=a.size()-1; i>=0; i--){
            int curr = a[i];
            while(st.top() > curr) st.pop();
            if(st.top() == -1) ans[i] = a[i];
            else ans[i] = a[i] - st.top();
            st.push(curr);
        }
        
        return ans;
    }
};