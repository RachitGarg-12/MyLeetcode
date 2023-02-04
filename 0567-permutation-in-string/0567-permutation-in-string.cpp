class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n>m) return false;
        
        vector<int> m1(26,0), m2(26,0);
        for(int i=0;i<n;i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        
        int count = 0;
        for(int i=0;i<26;i++)
            if(m1[i]==m2[i]) count++;
        
        for(int i=0;i<m-n;i++){
            if(count==26) 
                return true;
            
            int l = s2[i]-'a', r = s2[n+i]-'a';
            m2[l]--;
            if(m2[l]==m1[l]) 
                count++;
            else if(m2[l]==m1[l]-1) 
                count--;
            
            m2[r]++;
            if(m2[r]==m1[r]) 
                count++;
            else if(m2[r]==m1[r]+1) 
                count--;
        }
        
        return count==26;
    }
};