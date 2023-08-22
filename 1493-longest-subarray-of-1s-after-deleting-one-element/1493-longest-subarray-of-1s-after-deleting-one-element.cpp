class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int left=0;
        int zero=0;
        int right;
        for(right=0; right<nums.size();right++){
            if(nums[right]==0) zero++;
            if(zero>1){
                if(nums[left]==0) zero--;
                left++;
            } 
            ans=max(ans,right-left);
        }
        return ans;
    }
};