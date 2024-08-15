class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(auto i:bills){
            mp[i]++;
            if(i==10){
                if(mp[5]>0){
                   mp[i-5]--;
                }
                else{
                    return false;
                }
            }
            else if(i==20){
                if(mp[5]==0){return false;}
                if(mp[10]==0){
                    if(mp[5]>=3){
                        mp[5]-=3;
                    }
                    else{return false;}
                }
                else{
                    mp[10]--;
                    mp[5]--;
                }
                
            }
        }
        return true;
    }
};