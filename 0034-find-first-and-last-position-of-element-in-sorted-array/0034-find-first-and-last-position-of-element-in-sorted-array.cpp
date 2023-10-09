class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> ans;
       int res=-1, low=0, high=nums.size()-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(nums[mid]==target){
               res=mid;
               high=mid-1;
           } 
           else if(nums[mid]<target) low=mid+1;
           else high=mid-1;
       }
       ans.push_back(res);
       res=-1, low=0, high=nums.size()-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(nums[mid]==target){
               res=mid;
               low=mid+1;
           }
           else if(nums[mid]<target) low=mid+1;
           else high=mid-1;
       }
       ans.push_back(res);
       return ans;
    }
};