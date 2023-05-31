class Solution {
public:
    int minSwaps(string s) {
        int swaps=0;
        int open=0;
        for(auto i:s){
            if(i=='['){open++;}
            else{
                if(open>0){open--;}
                else{swaps++;open++;}
            }
        }
        return swaps;
    }
};