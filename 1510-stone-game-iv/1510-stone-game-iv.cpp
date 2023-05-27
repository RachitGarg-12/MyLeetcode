class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>a(n+1,true);
        // a[n] represents whether the person having the current chance with n number left can win or            not
        a[0]=false;
        int mx=1;
        for(int i=1;i<=n;i++){
            bool ans=false;
            for(int j=1;j*j<=i;j++){
                if(a[i-(j*j)]==false){ans=true;break;}
            }
            a[i]=ans;
        }
        return a[n];
    }
};