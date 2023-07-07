class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0, cnt=0;
        for(auto it:nums){
            sum+=it;
            
            if(sum==k) cnt++;
            
            if(mp.find(sum-k)!=mp.end()){
                cnt=cnt+mp[sum-k];
            }
            
            if(mp.find(sum)!=mp.end()) mp[sum]++;
            else mp[sum]=1;
        }
        return cnt;
    }
};