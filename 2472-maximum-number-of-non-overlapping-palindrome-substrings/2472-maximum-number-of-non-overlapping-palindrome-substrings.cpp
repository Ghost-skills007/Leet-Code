class Solution {
public:

    vector<vector<bool>> is_palindrome;
    vector<vector<bool>> is_calculated;
    
    bool p (string&s,int st, int ed) {
        if (st >= ed) return true;
        if (is_calculated[st][ed]) return is_palindrome[st][ed];
        
        is_calculated[st][ed] = true;
        
        if (s[st] == s[ed])
            is_palindrome[st][ed] = p(s,st+1, ed-1);
        else 
            is_palindrome[st][ed] = false;
        
        return is_palindrome[st][ed];
    }
int k1(int ind,int k,string&s,vector<int> &dp)
{
    if(ind>=s.size())return 0;
    if(dp[ind]!=-1)return dp[ind];
    int ans=ans=k1(ind+1,k,s,dp);    
    for(int i=ind+k-1;i<s.size();i++)
    {
        if(p(s,ind,i))ans=max(ans,1+k1(i+1,k,s,dp));
    }
    
    return dp[ind]=ans;
}
    int maxPalindromes(string s, int k) {
        vector<int> dp(s.size(),-1);
        int n=s.size();
        is_palindrome.resize(n, vector<bool>(n, false));
        is_calculated.resize(n, vector<bool>(n, false));
        vector<vector<int>> dp1(s.size(),vector<int>(s.size(),-1));
        return k1(0,k,s,dp);
    }
};