class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(a[i]>b[i]){
                ans+=a[i]-b[i];
            }
        }
        return ans;
    }
};