class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        if(targetX > 1 && targetY > 1){
            while(targetX % 2 == 0)
                targetX /= 2;
            while(targetY % 2 == 0)
                targetY /= 2;  
            while(targetX >= 1 && targetY >= 1){
                if(targetX < targetY)
                    targetY -= targetX;
                else if(targetX > targetY)
                    targetX -= targetY;
                else{
                    if(targetX == 1 && targetY == 1)
                        return true;
                    else
                        return false;    
                }    
            }      
        }
        return false;
           
    }
};