vector<vector<int>> M={
    {1, 1, 1},
    {1, 0, 0},
    {0, 1, 0}
};
vector<vector<int>> I={
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};
vector<vector<int>> operator*(vector<vector<int>> A,vector<vector<int>> B)
{
    int n=A.size(), k1=A[0].size(), k2=B.size(), m=B[0].size();
    if (k1!=k2) return {};
    vector<vector<int>> C(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<k1; k++)
                C[i][j]=(C[i][j]+(long long)A[i][k]*B[k][j]);
        }
    }
    return C;
}
vector<vector<int>> pow(vector<vector<int>> M, int n){
    if (n==0) return I;
    vector<vector<int>> A=(n&1)?M:I;
    return pow((M*M), n/2)*A;
}
class Solution {
public:
    // Matrix power
    int tribonacci(int n) {
        if (n==0) return 0;
        else if (n<=2) return 1;
        vector<vector<int>> A=
        pow(M, n-2)*vector<vector<int>>({{1}, {1},{0}});
        return A[0][0];
    }
};