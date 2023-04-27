class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0){return 0;}
        // for bulb to be on we need odd number of divisors
        //all have 1 and n as divisors , so we need to check if other divisors are in even/odd
        // num occur in pair till sqrt(n), so even num of divisor other than for sqaure num
        //because in square num on pair (sqrt(n),sqrt(n)) which just add 1 num so total odd divisor
        return sqrt(n);
    }
};