class Solution {
public:
int numberOfSteps (int num) {
     if(num==0) return 0;
   
     int len= ceil(log2(num+1));
     int setbits= __builtin_popcount(num);
     return len+setbits-1;
   }
};