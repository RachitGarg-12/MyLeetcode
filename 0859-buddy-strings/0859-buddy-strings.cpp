class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){return false;}
        map<char,int> ch,in;
        for(int i=0;i<s.size();i++){
            if(s==goal && ch.find(s[i])!=ch.end()){
                return true;
            }
            ch[s[i]]=i;
        }
        for(int i=0;i<s.size();i++){
           if(s[i]!=goal[i]){
               if(ch.find(goal[i])!=ch.end()){
                   string t=s;
                   char temp=t[i];
                   t[i]=goal[i];
                   t[ch[goal[i]]]=temp;
                   if(t==goal){return true;}
               }
           }
       } 
    return false;
        
    }
};