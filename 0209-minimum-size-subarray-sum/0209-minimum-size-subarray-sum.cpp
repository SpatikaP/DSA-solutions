class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, res=INT_MAX, sum=0, n=nums.size();
        while(r<n){
            sum+=nums[r++];
            while(sum>=target){
                res=min(res,r-l);
                sum-=nums[l++];
            }
        }
        return res==INT_MAX ? 0 : res;
    }
};