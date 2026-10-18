class Solution {
public:
    int mod=1000000007;
    long long inv(long long num) {
        if(num==1) return 1;
        return mod-mod/num*inv(mod%num)%mod;
    }
    int dfs(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 1;
        vector<int> x,y;
        for (int i=1;i<n;i++) {
            if(nums[i]<nums[0]) x.push_back(nums[i]);
            else y.push_back(nums[i]);
        }
        int a=x.size(),b=y.size();
        long long ans=1;
        for (int i=b+1;i<=a+b;i++) ans=ans*i%mod;
        for (int i=1;i<=a;i++) ans=ans*inv(i)%mod;
        return ans*dfs(x)%mod*dfs(y)%mod;
    }
    int numOfWays(vector<int>& nums) {
        return dfs(nums)-1;
    }
};