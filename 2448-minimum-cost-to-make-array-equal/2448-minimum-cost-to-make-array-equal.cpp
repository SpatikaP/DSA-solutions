class Solution {
public:
    
    long long solve(vector<int>& nums, vector<int>& cost, int m){
        
        long long res=0;
        
        for(int i=0; i<nums.size(); i++){
            res+=(long long)abs(nums[i]-m)*cost[i];
        }
        
        return res;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=INT_MAX;
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            long long cost1 = solve(nums,cost,mid);
            long long cost2 = solve(nums,cost,mid+1);
            
            ans=min(cost1,cost2);
            
            if(cost2>cost1) high=mid-1;
            else low=mid+1;

        }
        return ans == INT_MAX ? 0 : ans;
    }
};