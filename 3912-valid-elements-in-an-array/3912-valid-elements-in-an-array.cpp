class Solution {
public:
    vector<int> findValidElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0]=INT_MIN;
        rightmax[n-1]=INT_MIN;
        for(int i =1;i<n;i++){
            if(arr[i-1]>leftmax[i-1]){
                leftmax[i]=arr[i-1];
            }
            else{
                leftmax[i]=leftmax[i-1];
            }
        }

        for(int i =n-2;i>=0;i--){
            if(arr[i+1]>rightmax[i+1]){
                rightmax[i]=arr[i+1];
            }
            else{
                rightmax[i]=rightmax[i+1];
            }
        }
        vector<int> result;
        for(int i =0;i<n;i++){
            if(arr[i]>leftmax[i]||arr[i]>rightmax[i]){
                result.push_back(arr[i]);
            }

        }
        return result;
    
        
    }
};
