class Solution {
public:
    int dp[10010];
    int solve(vector<int> &coins, int amount){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX-1;
        for(int coin:coins){
            if((amount-coin)>=0) ans=min(ans, 1+ solve(coins,amount-coin));
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res = solve(coins,amount);
        return res == INT_MAX-1 ? -1: res;
    }
};
