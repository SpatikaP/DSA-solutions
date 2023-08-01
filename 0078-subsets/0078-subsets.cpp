class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int start, vector<int> &nums){
        ans.push_back(temp);
        for(int i=start; i<nums.size(); i++){
            temp.push_back(nums[i]);
            solve(ans,temp,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,0,nums);
        return ans;
    }
};