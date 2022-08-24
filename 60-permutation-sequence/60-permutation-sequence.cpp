class Solution {
public:
    string getPermutation(int n, int k) {
      vector<int> fact(10);fact[0]=1;
      for(int i=1;i<=9;i++){fact[i]=i*fact[i-1];}
        string s,t;
        for(int i=1;i<=n;i++){t+=to_string(i);}
        
        while(t.size()>=1){
        int cur=(k%fact[n-1])?(k/fact[n-1])+1:(k/fact[n-1]);
        s+=t[cur-1];t.erase(t.begin()+cur-1);
        if(k%fact[n-1]==0){k=fact[n-1];}
        else{k%=fact[n-1];}
        n--;
        }
        
        return s;
    }
};