class Solution {
public:
    vector<int> ans;int n,k;
    int len(int n){int a=0;
                  while(n){n/=10;a++;}
                  return a;
    }
    void nums(int cd){
        if(len(cd)==n){ans.push_back(cd);return;}       
        for(int i=0;i<10;i++){
            int l=cd%10;
            if(abs(l-i)==k){nums(cd*10+i);}
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        n=N;k=K;
        for(int i=1;i<10;i++){nums(i);}
        return ans;
    }
};