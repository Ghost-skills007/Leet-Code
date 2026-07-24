class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (arr[i] % k + k) % k;
        }
        
        std::sort(arr.begin(), arr.end());
        
        int i = 0;
        int j = arr.size() - 1;
        
        while (i < j) {
            if (arr[i] == 0) {
                if (arr[i + 1] != 0) return false;
                i += 2;
            } 
            else if (arr[i] + arr[j] == k) {
                i++;
                j--;
            } 
            else {
                return false;
            }
        }
        
        return true;
    }
};