class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0; //stores the maximum length of the subarray
        int left=0; //slinding window pointers
        int zero=0; //counter of zero
        int n=nums.size();
        
        //find the subarray with atmost one zero in it
        for(int right=0; right<n; right++){
            if(nums[right]==0) zero++;
            while(zero>1){
                // move the left pointer
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }
            // keep recording the lengths of all the possible subarrays and store the one with the maximum length
            ans = max( ans, right-left);
        }
        // if ans==n which means it contains only 1's but ATQ, you must delete one element
        return ans==n ? ans-1 : ans;
    }
};