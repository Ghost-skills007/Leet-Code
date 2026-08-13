class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = name.size(), m = typed.size();
        while(i < n && j < m) {
            int cnt = 0, ct = 0, id = i, idd = j;
            while(i < n && name[id] == name[i]) i++, cnt++;
            while(j < m && typed[idd] == typed[j]) j++, ct++;
            if(name[id] != typed[idd] || ct < cnt) return false;
        }
        if(i < n || j < m) return false;
        return true;
    }
};