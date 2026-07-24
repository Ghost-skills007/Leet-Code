class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top;
        for (int num : nums) {
            top.insert(num);
            if (top.size() > 3) {
                top.erase(top.begin());
            }
        }
        if (top.size() == 3) {
            return *top.begin();
        }
        return *top.rbegin();
    }
};