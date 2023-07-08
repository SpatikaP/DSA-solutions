class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int ans=0, sum=0, l=0, r=0;
        while(r<nums.size()){
            while(l<r && s.find(nums[r])!=s.end()){
                s.erase(nums[l]);
                sum-=nums[l++];
            }
            s.insert(nums[r]);
            sum+=nums[r++];
            ans=max(ans,sum);
        }
        return ans;
    }
};