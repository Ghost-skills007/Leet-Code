class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1,peak,down,i=1; //optimal o(n) o(1) up and down hill method
        while (i<ratings.size()){
            while (i<ratings.size() && ratings[i]==ratings[i-1]) {
                sum++;
                i++;
            }

            peak=1;
            while (i<ratings.size() && ratings[i]>ratings[i-1]) {
                peak++;
                sum+=peak;
                i++;
            }

            down=1;
            while (i<ratings.size() && ratings[i]<ratings[i-1]) {
                sum+=down;  
                down++;
                i++;
            }
            if (down>peak) sum+=down-peak;
        }
        return sum;
    }
};