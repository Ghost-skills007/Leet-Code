class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int size = timeSeries.size();
        
        int cnt = 0;
        for(int i = 0; i < size-1; i++){
            int interval = timeSeries[i+1]-timeSeries[i];
            cnt += min(duration, interval);
        }
        return cnt+duration;
    }
};