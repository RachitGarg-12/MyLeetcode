class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int, int> m;
        int i=0,j=0,ans=0;
        while(j<n){
            m[fruits[j]]++;
            if(m.size()<=2){ans=max(ans,j-i+1);}
            else{
                m[fruits[i]]--;
                if(!m[fruits[i]]){m.erase(fruits[i]);}
                i++;
            }
            j++;
        }
     return ans;
    }
};