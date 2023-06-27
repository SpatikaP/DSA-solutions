class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int,int> first,second,count;
        for(int i=0; i<nums.size(); i++){
            if(first.count(nums[i])==0) first[nums[i]]= i;
            second[nums[i]]=i;
            count[nums[i]]++;
        }
        
        int degree=0;
        for(auto x:count)
            degree = max(degree,x.second);
        
        int ans=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(count[nums[i]]==degree){
                int temp=second[nums[i]]-first[nums[i]]+1;
                ans=min(ans,temp);
            }
        }
        return ans;
    }
};