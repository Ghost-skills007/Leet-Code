class Solution {
public:
    int countKeyChanges(string s) {
        int change=0;
        for (int i=0; i< s.length()-1; i++){    
            if (s[i+1] != s[i] && s[i+1]!= s[i]+32 && s[i+1]!=s[i]-32 ){
                change++;
            }
        }
        return change; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna