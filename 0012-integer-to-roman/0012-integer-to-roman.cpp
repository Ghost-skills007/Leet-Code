class Solution {

public:
    string intToRoman(int num) 
    {
        ios_base::sync_with_stdio(0);
        vector<pair<int,string>>v{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ans;
        int i=0;
        while(num)
        {
            while(v[i].first>num)i++;
            ans+=v[i].second;
            num-=v[i].first;
        }
        return ans;
    }
};