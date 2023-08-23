class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt=0;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            if(sum==k) cnt++;
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            if(mp.find(sum)!=mp.end()) mp[sum]++;
            else mp[sum]=1;
        }
        return cnt;
    }
};