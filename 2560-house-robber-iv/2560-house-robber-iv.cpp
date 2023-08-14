class Solution {
public:
    bool chk(int mid, vector<int> &nums ,int k){
        int t=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid){
               t++;
               i+=1; 
            } 
        }
        return (t>=k);
    }
    int minCapability(vector<int>& nums, int k) {
       int low=1, high=1e9+1;
        int ans=1e9+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(chk(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};