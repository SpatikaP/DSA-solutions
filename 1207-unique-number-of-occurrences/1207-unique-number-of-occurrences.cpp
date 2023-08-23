class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto x:arr) mp[x]++;
        for(auto y:mp) s.insert(y.second);
        return mp.size()==s.size();
    }
};