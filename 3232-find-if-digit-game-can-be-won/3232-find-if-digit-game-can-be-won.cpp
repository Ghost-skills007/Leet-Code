class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum_single= 0;
        int sum_double= 0;      
        for (int i=0; i<nums.size(); i++){
            if ((nums[i])/10 == 0) sum_single+= nums[i];
            else sum_double+= nums[i];}
        if (sum_single!=sum_double) return true;
        return false;    
    }
};