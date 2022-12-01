class Solution {
public:
    bool halvesAreAlike(string s) {
        int a=0,b=0,n=s.size();
        
        for(int i=0;i<n/2;i++){
            char t= tolower(s[i]);
            if(t=='a' || t=='e' ||t=='i'||t=='o'||t=='u'){a++;}
        }
        for(int i=(n/2);i<n;i++){
            char t= tolower(s[i]);
            if(t=='a' || t=='e' ||t=='i'||t=='o'||t=='u'){b++;}
        }
        return (a==b);
    }
};