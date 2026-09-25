class Solution
{
public:
    set<vector<int>> unique;

    void solve(vector<int>& candidates, int target, int idx, vector<int> &combination, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            if (unique.find(combination) == unique.end())
            {
                ans.push_back(combination);
                unique.insert(combination);
            }
            return;
        }
        if (target < 0 || idx == candidates.size())
        {
            return;
        }

        combination.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx + 1, combination, ans); 
        solve(candidates, target - candidates[idx], idx, combination, ans);      
        combination.pop_back();                                                    
        solve(candidates, target, idx + 1, combination, ans);                        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> combination;
        solve(candidates, target, 0, combination, ans);
        return ans;
    }
};