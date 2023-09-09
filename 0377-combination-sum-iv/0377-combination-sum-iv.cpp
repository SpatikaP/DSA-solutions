class Solution {
public:
    int t[201][1001];
    
    int solve(int i, vector<int> nums, int target){
        
        if(target==0) return 1;
        
        if(i>=nums.size()) return 0;
        
        if(target<0) return 0;
        
        if(t[i][target]!=-1) return t[i][target];
        
        int take_idx = solve(0,nums,target-nums[i]);
        int reject_idx = solve(i+1,nums,target);
        
        return t[i][target]=take_idx+reject_idx;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(0,nums,target);
    }
};