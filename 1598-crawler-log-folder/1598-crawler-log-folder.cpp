class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>s;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){ //1
                if(!s.empty()){
                    s.pop();
                }
            }
            else if(logs[i]!="./"){ //2
                s.push(logs[i]);
            }
        }
        return s.size();
    }
};