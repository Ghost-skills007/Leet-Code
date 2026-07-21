class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        multiset<long long>st;

        int k = indexDiff +  1;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(st.empty()){
                st.insert(nums[r]);
                continue;
            }
            if(r - l + 1 > k){
                st.erase(st.find(nums[l]));
                l++;
            }
            auto it = st.lower_bound((long long)nums[r]);
            if(it != st.end() && abs(*it - nums[r]) <= valueDiff){
                return true;
            }
            if(it != st.begin() && abs(*(--it) - nums[r]) <= valueDiff){
                return true;
            }
            st.insert(nums[r]);
        }
        return false; 
    }
};