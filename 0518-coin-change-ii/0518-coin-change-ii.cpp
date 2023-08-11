class Solution {
public:
    int dp[301][5001];
    int solve(int i, vector<int> &coins, int amt){
        if(dp[i][amt]!=-1) return dp[i][amt];
        if(i==coins.size()) return 0;
        if(amt==0) return 1;
        if(amt<coins[i]) return dp[i][amt]=solve(i+1,coins,amt);
        int take=solve(i,coins,amt-coins[i]);
        int skip=solve(i+1,coins,amt);
        return dp[i][amt]=skip+take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,coins,amount);
    }
};