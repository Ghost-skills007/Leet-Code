class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi=1;
        int c=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                c++;
            }
            else{
                c=1;
            }
            if(maxi<c){
                maxi=c;
            }
        }
        return maxi;
    }
};
