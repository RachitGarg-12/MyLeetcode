class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        for(auto i:words){
            string temp="";
            for(auto j:i){
                temp += morse[j-'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};