class Solution {
public:
    int lcs(string &X, string &Y, int m, int n, int dp[][1001]){
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(X[m-1]==Y[n-1]) return dp[m][n] = 1+lcs(X,Y,m-1,n-1,dp);
        else return dp[m][n] = max(lcs(X,Y,m-1,n,dp),lcs(X,Y,m,n-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        int dp[1001][1001];
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                dp[i][j]=-1;
            }
        }
        return lcs(text1,text2,m,n,dp);
    }
};
