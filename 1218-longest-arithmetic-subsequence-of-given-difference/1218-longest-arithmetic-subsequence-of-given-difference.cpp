class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int ans;
        for(int i=0; i<arr.size(); i++){
            if(dp.count(arr[i]-diff)){
                dp[arr[i]]=dp[arr[i]-diff]+1;
            }
            else dp[arr[i]]=1;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};