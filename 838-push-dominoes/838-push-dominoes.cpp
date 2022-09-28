class Solution {
public:
     string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> v(n,0);
        vector<int> g(n,0);
        
        for(int i =1;i<n;i++){
            if(dominoes[i]=='.' and (dominoes[i-1]=='R' or dominoes[i-1]=='r')){
             dominoes[i]='r';   
                v[i] = 1+v[i-1];
            }
        }
        
        for(int i = n-2;i>=0;i--){
            if(dominoes[i]=='.' and (dominoes[i+1]=='L' or dominoes[i+1]=='l')){
                dominoes[i] = 'l';
                g[i] = 1+ g[i+1];
            }
            else if(dominoes[i]=='r' and (dominoes[i+1]=='L' or dominoes[i+1]=='l')){
                g[i] = 1+ g[i+1];
                if(g[i]==v[i]) dominoes[i] = '.';
                else if(g[i]<v[i]) dominoes[i] = 'l';
                else dominoes[i] = 'r';
            }
        }
        for(int i =0;i<n;i++){
            if(dominoes[i]=='l') dominoes[i]='L';
            if(dominoes[i]=='r') dominoes[i]='R';
        }
        return dominoes;
    }
};