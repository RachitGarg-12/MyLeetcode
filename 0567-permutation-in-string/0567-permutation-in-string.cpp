class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(),n=s2.size();
        if(k>n){return false;}
        sort(s1.begin(),s1.end());
        string cur="";
        for(int i=0;i<n;i++){
            if(i<k-1){cur+=s2[i];}
            else{
                if(i!=k-1){cur.erase(0,1);}
                cur+=s2[i];
                string temp=cur;
                sort(temp.begin(),temp.end());
                if(temp==s1){return true;}                
            }
        }
       return false; 
    }
};