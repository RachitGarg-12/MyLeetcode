class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l2=0;
        for(int l1=0 ;l1<str1.length()&&l2<str2.length(); l1++)
        {
            if(str1[l1]==str2[l2])
             l2++;
            else {
                if(str1[l1]!='z' &&  str1[l1]+1==str2[l2])
                   l2++;
                else if(str1[l1]=='z' && str2[l2]=='a' )
                    l2++;
            }
        }
        if(l2==str2.length())
            return true;
        else
            return false;
    }
};