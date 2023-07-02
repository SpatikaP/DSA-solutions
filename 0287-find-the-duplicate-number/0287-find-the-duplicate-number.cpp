class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(int i=0; i<mp.size(); i++){
            if(mp[i]>1) return i;
        }
        return -1;
    }
};