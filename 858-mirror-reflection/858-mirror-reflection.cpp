class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm =p *q /(gcd(p,q));
        int moves=lcm/q;int box=lcm/p;
        if(moves%2==0){return 2;}
        else if(moves%2 && box%2==0){return 0;}
        else{return 1;}
    }
};