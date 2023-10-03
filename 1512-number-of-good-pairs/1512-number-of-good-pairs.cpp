class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
          for(int j=0;j<i;j++){
           if(nums[j]==nums[i] && j<i) 
           {
               x++;
           }
          }
        }
        return x;
    }
};