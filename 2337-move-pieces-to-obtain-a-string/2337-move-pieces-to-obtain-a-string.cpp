class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        for(int i=0,j=0;i<n || j<n;i++,j++){
            while(i<n && start[i]=='_'){i++;}
            while(j<n && target[j]=='_'){j++;}
            char s=start[i];
            if(s!=target[j])return false;
            if(s=='L' && i<j)return false;
            if(s=='R' && i>j)return false;
        }
        return true;
    }
};