class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0,cnt10=0;
        for(auto i:bills){
            if(i==5){cnt5++;}
            if(i==10){
                cnt10++;
                if(cnt5>0){
                   cnt5--;
                }
                else{
                    return false;
                }
            }
            else if(i==20){
                if(cnt5==0){return false;}
                if(cnt10==0){
                    if(cnt5>=3){
                        cnt5-=3;
                    }
                    else{return false;}
                }
                else{
                    cnt10--;
                    cnt5--;
                }
                
            }
        }
        return true;
    }
};