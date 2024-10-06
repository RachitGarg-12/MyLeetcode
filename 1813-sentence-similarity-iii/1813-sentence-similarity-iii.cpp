class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> sen1,sen2;
        string cur="";
        for(auto i:sentence1){
            if(i==' '){
                sen1.push_back(cur);
                cur="";
            }
            else{
                cur+=i;
            }
        }
        sen1.push_back(cur);
        cur="";
        for(auto i:sentence2){
            if(i==' '){
                sen2.push_back(cur);
                cur="";
            }
            else{
                cur+=i;
            }
        }
        sen2.push_back(cur);
        
        if(sen1.size()<sen2.size()){
            swap(sen1,sen2);
        }        
        
        int start = 0, end = 0;
        int n1 = sen1.size(), n2 = sen2.size();
        
        // Compare from the start
        while (start < n2 && sen1[start] == sen2[start]) start++;
        
        // Compare from the end
        while (end < n2 && sen1[n1 - end - 1] == sen2[n2 - end - 1]) end++;
        
        // Check if the remaining unmatched part is in the middle
        return start + end >= n2;       
        
    }
};