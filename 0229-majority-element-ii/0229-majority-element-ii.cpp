class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int k=nums.size()/3;
        vector<int> v;
        for(auto e:nums)
            mp[e]++;
        for(auto e:mp)
            if(e.second>k)
                v.push_back(e.first);
        return v;
    }
};