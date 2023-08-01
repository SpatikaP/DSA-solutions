class Solution {
public:
    void solve(int start,vector<vector<int>> &ans, vector<int> &temp,vector<int>& nums, int t){
        if(t==0){
            ans.push_back(temp);
        }
        if(t<0) return;
        for(int i=start; i<nums.size(); i++){
            temp.push_back(nums[i]);
            solve(i,ans,temp,nums,t-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,ans,temp,candidates,target);
        return ans;
    }
};