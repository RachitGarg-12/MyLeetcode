class Solution {
public:
    string reverseVowels(string s) {
        string a="";
        for(auto i:s){
            char c=(char)tolower(i);
            if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u') a+=i;
        }
        reverse(a.begin(),a.end());int f=0;
        for(int i=0;i<s.size();i++){
            char c=(char)tolower(s[i]);
            if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u'){s[i]=a[f];f++;}
        }
        return s;
    }
};