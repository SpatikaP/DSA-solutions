class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<groupSizes.size(); i++){
            int L=groupSizes[i];
            mp[L].push_back(i);
            if(mp[L].size()==L){
                ans.push_back(mp[L]);
                mp[L]={};
            }
        }
        return ans;
    }
};