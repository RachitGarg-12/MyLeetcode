class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        bool b=true;
        string s="";
        while(i<word1.size() && j<word2.size()){
            if(b ){s+=word1[i];b=false;i++;}
            else{s+=word2[j];b=true;j++;}
        }
        while(i<word1.size()){s+=word1[i];i++;}
        while(j<word2.size()){s+=word2[j];j++;}
        return s;
    }
};