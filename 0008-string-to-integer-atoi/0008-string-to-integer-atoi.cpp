class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        bool flag=true;
        long long ans=0;
        int sign=1;
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            if(s[i]==' '&& flag==true){
                continue;
            }

            else if(num>=0&&num<=9){
                ans=(ans*10)+num;
                flag=false;
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;
            }

            else if(s[i]=='-'&&flag==true){
                sign=-1;
                flag=false;
            }
             else if(s[i]=='+'&&flag==true){
                sign=1;
                flag=false;
            }
            else {
                break;
            }
        }
        return (int)(ans*sign);
    }
};