class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        int ans=0;
        for(auto i:tasks){m[i]++;}
        for(auto i:m){
            if(i.second<2){return -1;}
            if(i.second%3==0){ans+=i.second/3;}
            else if(i.second%2 && i.second%3==1){
                ans += (i.second-4)/3 + 2;
            }
            else if(i.second%2==0 && i.second%3==1){
               int th=i.second/6,to=i.second%6; 
                ans+=(th*2)+(to/2);}
            else if(i.second%2 && i.second%3==2){
                ans += (i.second-4)/3 + 2;
            }
            else if(i.second%2==0 && i.second%3==2){
                ans += (i.second-2)/3 + 1;
            }
        }
        return ans;
    }
};