class Solution {
public:
    int minElement(vector<int>& ab) {
        int s = INT_MAX;
        
        for (int na : ab) {
            int an = 0;
            
            while (na > 0) {
                an += na % 10;
                na /= 10;
            }
            
            s = min(s, an);
        }
        
        return s;
    }
};