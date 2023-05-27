class Solution {
public:
//     int f(int n,int turn){
        
//     }
    bool winnerSquareGame(int n) {
        vector<bool>a(n+1,true);
        a[0]=false;a[1]=true;
        int mx=1;
        for(int i=2;i<=n;i++){
            bool ans=false;
            for(int j=1;j*j<=i;j++){
                if(a[i-(j*j)]==false){ans=true;break;}
            }
            a[i]=ans;
        }
        return a[n];
    }
};