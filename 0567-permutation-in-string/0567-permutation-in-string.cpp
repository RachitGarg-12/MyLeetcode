class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(),n=s2.size();
        if(k>n){return false;}
        vector<int> m1(26),m2(26);
        for(auto i:s1){m1[i-'a']++;}
        for(int i=0;i<n;i++){
            if(i<k-1){m2[s2[i]-'a']++;}
            else{
                if(i!=k-1){m2[s2[i-k]-'a']--;}
                m2[s2[i]-'a']++;
                bool b=true;
                for(int i=0;i<26;i++){if(m1[i]!=m2[i]){b=false;break;}}
                if(b){return true;}
            }
        }
       return false; 
    }
};