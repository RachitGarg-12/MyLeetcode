class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        int n=path.size();
        map<pair<int,int>,bool> mp;
        mp[{0,0}]=true;
        for(int i=0;i<n;i++){
            if(path[i]=='N'){x++;}
            if(path[i]=='S'){x--;}
            if(path[i]=='E'){y++;}
            if(path[i]=='W'){y--;}
            if(mp.find({x,y})!=mp.end()){return true;}
            mp[{x,y}]=true;
        }
        return false;
    }
};