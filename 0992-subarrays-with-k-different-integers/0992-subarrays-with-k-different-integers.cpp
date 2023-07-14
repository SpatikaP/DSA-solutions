class Solution {
public:
    int atmost(vector<int> v, int k){
        int cnt=0;
        unordered_map<int,int> mp;
        int l=0;
        for(int r=0; r<v.size(); r++){
            mp[v[r]]++;
            while(mp.size()>k){
                auto it = mp.find(v[l]);
                it->second--;
                if(it->second==0) mp.erase(it);
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};