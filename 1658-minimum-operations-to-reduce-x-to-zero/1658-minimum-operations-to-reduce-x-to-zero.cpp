class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(auto e:nums) sum+=e;
        int target=sum-x;
        int total=0, left=0, len=0;
        bool found=false;
        for(int right=0; right<nums.size(); right++){
            total+=nums[right];
            while(left<=right && total>target){
                total-=nums[left++];
            }
            if(total==target){
                found=true;
                len=max(len,right-left+1);
            }
        }
        int n = nums.size();
        return found ? n-len : -1;
    }
};