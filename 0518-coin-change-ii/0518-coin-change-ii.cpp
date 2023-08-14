class Solution {
public:
    int dp[301][5001];
    int solve(int i, int amt, vector<int> &coins){
        if(i>=coins.size()) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        if(amt==0) return 1;
        if(amt<coins[i]) return dp[i][amt]=solve(i+1,amt,coins);
        int take=solve(i,amt-coins[i],coins);
        int skip=solve(i+1,amt,coins);
        return dp[i][amt]=skip+take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};