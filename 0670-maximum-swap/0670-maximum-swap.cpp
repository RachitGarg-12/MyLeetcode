class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string a=s;
        sort(s.begin(),s.end(),greater<char>());
        int n=s.size();
        for(int i=0;i<n;i++){
            if(a[i]!=s[i]){
                for(int j=n-1;j>i;j--){
                    if(a[j]==s[i]){
                        swap(a[i],a[j]);
                        break;
                    }
                }
                break;
            }
        }
        int ans=stoi(a);
        return ans;
    }
};