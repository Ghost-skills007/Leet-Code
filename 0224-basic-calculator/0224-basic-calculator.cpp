class Solution {
public:
    int calculate(string s) {
        vector<int> storage;
        int current_answer = 0;
        int current_sign = 1; 
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                long long number = 0;
                while (i < s.length() && isdigit(s[i])) {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                i--; 
                
                current_answer = current_answer + (current_sign * number);
            } 
            else if (c == '+') {
                current_sign = 1;
            } 
            else if (c == '-') {
                current_sign = -1;
            } 
            else if (c == '(') {
                storage.push_back(current_answer);
                storage.push_back(current_sign);
                
                current_answer = 0;
                current_sign = 1;
            } 
            else if (c == ')') {
               
                int old_sign = storage.back();
                storage.pop_back();
                
                int old_answer = storage.back();
                storage.pop_back();
                
                current_answer = old_answer + (old_sign * current_answer);
            }
        }
        
        return current_answer;
    }
};