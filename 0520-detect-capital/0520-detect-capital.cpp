class Solution {
public:
    bool detectCapitalUse(string word) {
        int tot=0;
        bool b=false;
        if(word[0]-'A'>=0 && word[0]-'A'<=25){b=true;tot++;}
        for(int i=1;i<word.size();i++){
            if(word[i]-'A'>=0 && word[i]-'A'<=25){
                if(b==false)return false;
                tot++;
            }
        }
        if(b && (tot==1 || tot==word.size()))return true;
        if(b==false && tot==0)return true;
        return false;
    }
};