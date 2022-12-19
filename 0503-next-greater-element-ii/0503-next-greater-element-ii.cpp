class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=2*n;i>=0;i--){
            while(!s.empty() && s.top()<=a[i%n]){s.pop();}
            if(i<n){
                if(!s.empty()){ans[i]=s.top();}
                else{ans[i]=-1;}
            }
            s.push(a[i%n]);
        }
        return ans;
    }
};