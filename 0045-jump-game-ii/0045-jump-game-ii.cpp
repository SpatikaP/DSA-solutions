class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0;
        int current=0;
        int jump=0;
        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest,i+nums[i]);
            if(i==current){
                jump++;
                current=farthest;
            }
        }
        return jump;
    }
};