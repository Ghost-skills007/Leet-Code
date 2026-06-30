class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastPos(3, -1);
        int count = 0;
        
        for (int right = 0; right < s.length(); right++) {
            lastPos[s[right] - 'a'] = right;
            
            if (lastPos[0] != -1 && lastPos[1] != -1 && lastPos[2] != -1) {
                count += (min({lastPos[0], lastPos[1], lastPos[2]}) + 1);
            }
        }
        
        return count;
    }
};