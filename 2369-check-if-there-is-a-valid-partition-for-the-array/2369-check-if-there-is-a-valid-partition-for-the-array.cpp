class Solution {
public:
    int n;
    int t[100001];
    bool solve(int i,vector<int> &nums){
        if(i>=n) return true;
        bool res=false;
        if(t[i]!=-1) return t[i];
        if(i+1<n && nums[i]==nums[i+1])
            res |=solve(i+2,nums);
            
        if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
            res |=solve(i+3,nums);
            
        if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
            res |=solve(i+3,nums);
        
        return t[i]=res;
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};