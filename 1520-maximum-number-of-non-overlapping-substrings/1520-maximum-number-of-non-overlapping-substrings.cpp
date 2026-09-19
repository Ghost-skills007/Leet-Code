class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26,-1);
        vector<int> end(26,0);
        vector<int> skip(26,0);
        vector<string> result;
        for (int i=0;i<s.size();i++){
            int ind = s[i]-'a';
            if (start[ind]==-1) start[ind] = i;;
            end[ind] =i;
        }
        for(int i=0;i<26;i++){
            if (start[i]==-1) continue;
            for (int k = start[i];k<=end[i];k++){
                if (start[s[k]-'a']<start[i]){
                    skip[i]=1;  
                    break;
                }
                else end[i] = max(end[i],end[s[k]-'a']);
            }
        }
        int cut = INT_MAX;
        for (int i=s.size()-1;i>=0;i--){
            if (i==start[s[i]-'a'] 
            && end[s[i]-'a']<cut && 
            !skip[s[i]-'a']
            ){
                result.push_back(s.substr(i,end[s[i]-'a'] - i +1)); 
                cut=i; 
            }
                
        }

        return result;

    }
};