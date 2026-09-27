class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> sortedCandidates = candidates;
        std::sort(sortedCandidates.begin(), sortedCandidates.end());

        std::vector<std::vector<int>> output;
        std::vector<int> subset;
        helper(subset, 0, sortedCandidates, target, output);

        return output;
    }

private: 
    void helper(std::vector<int>& subset, int index, std::vector<int>& candidates, int target, std::vector<std::vector<int>>& output)
    {
        if(target == 0)
        {
            output.push_back(subset);
            return;
        }
        else if(target < 0  || index == candidates.size())
        {
            return;
        }

        subset.push_back(candidates[index]);
        helper(subset, index + 1, candidates, target - candidates[index], output);
        subset.pop_back();

        const auto cand = candidates[index];
        ++index;
        while(index < candidates.size() && candidates[index] == cand)
        {
            ++index;
        }
        helper(subset, index, candidates, target, output);
    }
};