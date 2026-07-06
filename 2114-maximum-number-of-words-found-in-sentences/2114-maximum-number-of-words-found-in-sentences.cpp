class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        
        for (const string& sentence : sentences) {
            int currentWord = 1; 
            
            for (char c : sentence) {
                if (c == ' ') {
                    currentWord++;
                }
            }
            
            if (currentWord > max) {
                max= currentWord;
            }
        }
        
        return max;
    }
};