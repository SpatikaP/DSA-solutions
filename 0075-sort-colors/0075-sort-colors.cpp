class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0, m=0, e=nums.size()-1;
        while(m<=e){
            if(nums[m]==0){
                swap(nums,s,m);
                s++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums,m,e);
                e--;
            }
        }
    }
    
    void swap(vector<int>& nums, int a, int b) {
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    
};