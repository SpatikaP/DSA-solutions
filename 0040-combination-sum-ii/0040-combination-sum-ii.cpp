class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int start, vector<int> &nums, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(ans,temp,i+1,nums,target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,0,nums,target);
        return ans;
    }
};