class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int profit=0;
        int effectiveBuy=prices[0];
        for(int i=1; i<prices.size(); i++){
            profit=max(profit,prices[i]-effectiveBuy-fee);
            effectiveBuy=min(effectiveBuy,prices[i]-profit);
        }
        return profit;
    }
};