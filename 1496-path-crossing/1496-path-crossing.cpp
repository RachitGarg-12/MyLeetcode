class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        int n=path.size();
        set<pair<int,int>> s;
        s.insert({0,0});
        for(int i=0;i<n;i++){
            if(path[i]=='N'){x++;}
            if(path[i]=='S'){x--;}
            if(path[i]=='E'){y++;}
            if(path[i]=='W'){y--;}
            if(s.find({x,y})!=s.end()){return true;}
            s.insert({x,y});
        }
        return false;
    }
};