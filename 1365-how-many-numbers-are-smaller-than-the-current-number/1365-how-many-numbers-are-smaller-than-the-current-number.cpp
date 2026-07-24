class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        int big_count = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            if (j != i && nums[j] < nums[i]) {
                big_count++;
            }
        }
        
        result.push_back(big_count);
    }
    
    return result;  
    }
};