class Solution {
public:
    vector<vector<int>> quan={{100,0},{75,25},{50,50},{25,75}};
    map<pair<int,int>,double> dp;
    double prob(int a,int b){
        if(a<=0 && b<=0){return 0.5;}
        if(a<=0){return 1;}
        if(b<=0){return 0;}
        if(dp.find({a,b})!=dp.end()){return dp[{a,b}];}
        double ans=0;
        for(int i=0;i<4;i++){
            ans+=0.25*prob(a-quan[i][0],b-quan[i][1]);
        }
        return dp[{a,b}]=ans;
    }
    double soupServings(int n) {
        if(n>5000){return 1;}
        return prob(n,n);
    }
};