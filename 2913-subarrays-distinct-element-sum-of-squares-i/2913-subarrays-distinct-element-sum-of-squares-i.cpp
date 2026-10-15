class Solution {
public:
    int sumCounts(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n= nums.size(),ans=0;
        for (int i=0; i <n; i++){
            for (int j=i; j<n; j++){
                set<int>s;
                for (int k=i; k<=j; k++){
                    s.insert(nums[k]);
                }
                int ss=s.size();
                ans+=ss*ss;
            }
        }
        return ans;
    }
};