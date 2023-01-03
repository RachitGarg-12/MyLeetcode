class Solution {
public:
    string minimizeResult(string exp) {
     int mn= INT_MAX, a=-1,b=-1 ,n= exp.size(), plus=exp.find('+');
    for(int i=0;i<plus;i++){
        for(int j=plus+1;j<n;j++){
            //extract 4 Integers
            int n1= stoi(exp.substr(0,i)==""?"1":exp.substr(0,i));   //from 0 to i index we have one integer
            int n2= stoi(exp.substr(i,plus-i));                      //from i to plus-1 index -> we have one integer
            int n3= stoi(exp.substr(plus+1,j-plus));                 //from plus+1 index to j , we have one value
            int n4= stoi(exp.substr(j+1)==""?"1":exp.substr(j+1));   //from j to last we have one value
            //update minimum by updating a and b variable
            if(n1*(n2+n3)*n4<mn) mn= n1*(n2+n3)*n4 ,a=i ,b=j+1;
        }
    }
    //insert "(" at a-position and ")" at b-position we captured above
    exp.insert(a,"(");
    if(b==n) exp+=")";   
    else exp.insert(b+1,")");
        return exp;
    }
};