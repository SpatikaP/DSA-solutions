class Solution {
public:
    bool chk(vector<int> &nums, int k, int mid){
        int total=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid){
               total++;
               i+=1; 
            } 
        }
        return (total>=k);
    }
    int minCapability(vector<int>& nums, int k) {
        int low=1, high=1e9+1;
        int ans=1e9+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(chk(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};