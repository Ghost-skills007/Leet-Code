class Solution {
public:
    string convertToBase7(int num) {
        string s="";
        int n=num;
        num=abs(num-0);
        if(num==0)return "0";
        while(num>0){
            int rem=num%7;
            num=num/7;
            s=to_string(rem)+s;
        }if(n<0){s='-'+s;}
        return s;
    }
};