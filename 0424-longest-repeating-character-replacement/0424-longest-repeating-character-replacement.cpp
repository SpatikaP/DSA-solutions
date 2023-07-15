class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0, maxFreq=0, ans=0;
        unordered_map<char,int> mp;
        for(int end=0; end<s.size(); end++){
            mp[s[end]]++;
            maxFreq=max(maxFreq,mp[s[end]]);
            if((end-start+1)-maxFreq>k){
                mp[s[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};