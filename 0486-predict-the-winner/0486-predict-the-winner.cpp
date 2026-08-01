class Solution {
public:
    int f(int i,int j,vector<int>& nums){
        int n = nums.size();
        if(i > j) return 0;
        if(i == j) return nums[i];
        int take_i = nums[i] + min(f(i+2,j,nums),f(i+1,j-1,nums));
        int take_j = nums[j] + min(f(i+1,j-1,nums),f(i,j-2,nums));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int score1 = f(0,n-1,nums);
        int sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int score2 = sum - score1;
        return (score1>=score2);
        
    }
};