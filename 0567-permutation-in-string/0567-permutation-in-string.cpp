class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(),n=s2.size();
        if(k>n){return false;}
        unordered_map<char,int> m1,m2;
        for(auto i:s1){m1[i]++;}
        for(int i=0;i<n;i++){
            if(i<k-1){m2[s2[i]]++;}
            else{
                if(i!=k-1){m2[s2[i-k]]--;}
                m2[s2[i]]++;
                bool b=true;
                for(auto i:s1){if(m1[i]!=m2[i]){b=false;break;}}
                if(b){return true;}
            }
        }
       return false; 
    }
};