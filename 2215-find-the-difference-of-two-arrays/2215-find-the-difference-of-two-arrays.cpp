class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> newArr(2);
        for (int i = 0; i < nums1.size(); i++) {
            bool commonHai = false;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    commonHai = true;
                    break;
                }
            }
            if (!commonHai) {
                bool alreadySaved = false;
                for (int k = 0; k < newArr[0].size(); k++) {
                    if (newArr[0][k] == nums1[i]) {
                        alreadySaved = true;
                        break;
                    }
                }  
                if (!alreadySaved) {
                    newArr[0].push_back(nums1[i]);
                }}}
        for (int i = 0; i < nums2.size(); i++) {
            bool commonHai = false;
            
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    commonHai = true;
                    break;
                }}
            if (!commonHai) {
                bool alreadySaved = false;
                for (int k = 0; k < newArr[1].size(); k++) {
                    if (newArr[1][k] == nums2[i]) {
                        alreadySaved = true;
                        break;
                    }}
                
                if (!alreadySaved) {
                    newArr[1].push_back(nums2[i]);
                }}}
        return newArr;
    }
};