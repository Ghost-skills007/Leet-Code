class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        
        for (const string& sentence : sentences) {
            int currentWordCount = 1; 
            
            for (char c : sentence) {
                if (c == ' ') {
                    currentWordCount++;
                }
            }
            
            if (currentWordCount > maxWords) {
                maxWords = currentWordCount;
            }
        }
        
        return maxWords;
    }
};