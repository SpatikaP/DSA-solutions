class Solution {
public:
    int solve(int i, int j, vector<int> &nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        int take_i = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j = nums[j] + min(solve(i,j-2,nums), solve(i+1,j-1,nums));
        return max(take_i,take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        sum=accumulate(begin(nums),end(nums),0);
        int p1 = solve(0,nums.size()-1,nums);
        int p2 = sum-p1;
        return p1>=p2;
    }
};